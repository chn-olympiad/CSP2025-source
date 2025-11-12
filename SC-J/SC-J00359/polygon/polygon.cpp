#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=998244353;
int a[5005];
ll n,ans=0;
int m=0;
void dfs(int k,ll sum,int mx){
	if(k>n){
		if(sum>mx*2){
			ans+=1;
			ans%=N;
		}
		return ;
	}
	dfs(k+1,sum+a[k],max(a[k],mx));
	dfs(k+1,sum,mx);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	sort(a+1,a+1+n);
	bool q=a[1]+a[2]>a[3];
	if(n<=3){
		cout<<q;
	}else if(n<=26){
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}