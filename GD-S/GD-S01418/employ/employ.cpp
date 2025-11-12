#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
#define popc __builtin_popcount
using namespace std;
const int mod=998244353;
int n,m,s[505],f[1<<18][19],c[505];
char ch;
void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ch,s[i]=ch-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	f[0][0]=1;
	for(int i=0;i<1<<n;i++){
		int pc=popc(i);
		for(int j=0;j<=pc;j++){
			for(int k=1;k<=n;k++){
				if(i>>(k-1)&1)continue;
				add(f[i|1<<(k-1)][j+(s[pc+1]&&pc-j<c[k])],f[i][j]);
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)add(ans,f[(1<<n)-1][i]);
	cout<<ans<<endl;
	return 0;
}/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

18 5
110111101111010011
6 0 4 2 1 2 5 4 3 3 1 0 4 8 4 2 5 9

*/
