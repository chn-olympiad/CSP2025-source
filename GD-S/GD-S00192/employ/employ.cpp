#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
const int maxn=1e6+100;
int n,m,c[maxn],p[maxn];
string s;
int d[(1<<18)][19];
void work(){
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	if (n<=18){
		int ans=0;
		d[0][0]=1;
		for (int i=0;i<(1<<n);i++){
			int cnt=__builtin_popcount(i);
			for (int j=0;j<=cnt;j++){
				for (int k=1;k<=n;k++){
					if ((i>>(k-1))&1)continue;
					if (cnt-j<c[k]&&s[cnt]!='0'){
						d[i|(1<<(k-1))][j+1]=(d[i|(1<<(k-1))][j+1]+d[i][j])%mod;
					}
					else{
						d[i|(1<<(k-1))][j]=(d[i|(1<<(k-1))][j]+d[i][j])%mod;
					}
				}
			}
		}
		for (int i=m;i<=n;i++){
			ans=(ans+d[(1<<n)-1][i])%mod;	
		}
		cout<<ans%mod;
		return ;
	}
	cout<<0;
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while (t--){work();}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
3 2
101
1 1 23

18 5
111011101011011011
1 2 3 4 1 2 3 4 2 3 2 2 6 6 6 6 6 6 

*/
