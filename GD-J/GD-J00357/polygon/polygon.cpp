#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
int n,a[5005],cnt;
#define pii pair<int,int>
#define mp make_pair
unordered_map<unsigned long long,bool> pd;
const int mod=998244353;
int qpow(int a,int b,int mod){
	int ans=1;
	for(int i=1;i<=b;i++) ans=ans*a%mod;
	return ans;
} 
void dfs(int now,int sum,int maxx,int many,unsigned long long tran){
    if(sum>2*maxx&&many>=3&&(!pd[tran])){
        pd[tran]=true;
        cnt=cnt+1;
    }
    if(now==n+1)  return;
    if(many+n-now<2) return;
    dfs(now+1,sum+a[now],max(maxx,a[now]),many+1,tran|(1<<now));
    dfs(now+1,sum,maxx,many,tran);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    int ma=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	ma=max(ma,a[i]);
	}
	if(ma==1){
		cout<<qpow(2,n,mod)-n-(n-1)*n/2-1;
		return 0;
	}
    dfs(1,0,0,0,0LL);
    cout<<cnt;
    return 0;
}
