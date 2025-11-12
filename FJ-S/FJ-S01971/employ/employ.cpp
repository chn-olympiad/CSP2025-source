#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],N;
long long ans[650005][23];
string s;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,N=1<<n;
	for(int i=0;i<n;++i){
		cin>>c[i];
	}
	ans[0][0]=1;
	for(int i=1;i<N;++i)for(int j=0;j<=n-m;++j){
		int v=i,t=0,u=1,e=0;
		while(v>0)t+=(v&1),v>>=1;
		v=i;
		while(v>0){
			if(v&1){
				if(j>=c[e]||s[t-1]=='0')(ans[i][j+1]+=ans[i^u][j])%=mod;
				else (ans[i][j]+=ans[i^u][j])%=mod;
				
			}
			v>>=1,++e,u<<=1;
		}
	}
	long long sum=0;
	for(int i=0;i<=n-m;++i)(sum+=ans[N-1][i])%=mod;
	cout<<sum<<"\n"; 
	return 0;
}
