#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[1<<18][20];
int a[20];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	cin >> s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		int pop=0;
		for(int j=0;j<n;j++) if(i&(1<<j)) pop++;
		for(int j=0;j<=pop;j++)
		{
			for(int k=0;k<n;k++) if(!(i&(1<<k)))
			{
				int tmp=((a[k+1]>pop-j) && s[pop]=='1');
				f[i^(1<<k)][j+tmp]=(f[i^(1<<k)][j+tmp]+f[i][j])%mod;
			}
//			cout << i << ' ' << j << ' ' << f[i][j] << endl;
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) ans=(ans+f[(1<<n)-1][i])%mod; 
	printf("%d\n",ans);
	return 0;
}
