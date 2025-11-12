#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],f[505][505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
		cin>>s[i];
	for (int i=1;i<=m;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++){
			if (s[i]==0)
				f[i][j]=f[i-1][j]+f[i][j]+c[i];
			
		}
	}
	if (f[i][j]==m)
	cout<<m/2;
 } 
