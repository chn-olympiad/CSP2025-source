#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1;
const int N=1e5+10,mod=998244353;
long long c[N],a[N],ans=0,res=1;
int fl[N];
int n1;
void dfs(int x,int d){
//	cout<<x<<" "<<d<<"\n";
	if(x>n1){
		if(d>=m){
			ans+=res;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!fl[i]){
			fl[i]=1;
			if(c[i]+d<a[x]){
				dfs(x+1,d);
			}
			else dfs(x+1,d+1);
			fl[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		if(s1[i-1]=='1')++n1,a[n1]=i;
		cin>>c[i];
	}
	for(int i=1;i<=n-n1;i++){
		res=res*i%mod;
	}
//	cout<<n1<<" "<<res;
	if(n1<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
}
