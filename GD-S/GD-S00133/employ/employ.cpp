#include <iostream>

using namespace std;

const int N=510,mod=998244353;

int n,m,c[N],f[1<<18][20];
char ss[N];

void bf(){
	f[0][0]=1;
	for (int s=0;s<1<<n;s++)
		for (int i=0;i<=n;i++)
			if (f[s][i])
				for (int j=1;j<=n;j++)
					if (!(s>>j-1&1))
						(f[s|1<<j-1][i+(i>=c[j]||ss[__builtin_popcount(s)+1]=='0')]+=f[s][i])%=mod;
	int ans=0;
	for (int i=0;i<=n-m;i++)
		(ans+=f[(1<<n)-1][i])%=mod;
	cout<<ans<<endl;
}

int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>ss+1;
	for (int i=1;i<=n;i++) cin>>c[i];
	if (n<=18) bf();
	return 0;
} 
