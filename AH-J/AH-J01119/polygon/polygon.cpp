#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
bool f=true;
int n,a[5010];
ll tmpans=0,ans=0;
void dfs(int cur,int sum,int cnt,int maxn){
    if(cur>n){
		if(sum>2*maxn&&cnt>=3){
			tmpans++;
			tmpans%=mod;
		}
		return ;
	}
    dfs(cur+1,sum,cnt,maxn);
    dfs(cur+1,sum+a[cur],cnt+1,a[cur]);
}
void special(){
	ans=1;
	for(int i=3;i<=n;i++){
		for(int j=n;j>=n-i+1;j--)
			ans=(ans*j)%mod;
		for(int j=1;j<=i;j++)
			ans=(ans/j)%mod;
	}
	ans%=mod;
	cout<<ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			f=false;
	}
	if(f==true)
		special();
    sort(a+1,a+n+1);
    dfs(1,0,0,0);
    ans=tmpans;
    cout<<ans;
    return 0;
}
