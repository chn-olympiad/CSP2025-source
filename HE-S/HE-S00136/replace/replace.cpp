#include <bits/stdc++.h>
using namespace std;
string s[2000005][3],qu[2000005][3],x1,x2,z1,z2,w1,w2;
int n,q,ans[2000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=2;j++)
		{
			cin >> s[i][j];
		}
	}
	for (int i=1;i<=q;i++)
	{
		for (int j=1;j<=2;j++)
		{
			cin >> qu[i][j];
		}
	}
	for (int i=1;i<=q;i++)
	{
		w1="";
		w2="";
		z1="";
		z2="";
		x1="";
		x2="";
		for (int j=0;j<qu[i][1].size();j++)
		{
			if (j>=1)
			{
				w1+=qu[i][1][j-1];
				w2+=qu[i][2][j-1];
			}
			for (int k=j;k<qu[i][1].size();k++)
			{
				x1+=qu[i][1][k];
				x2+=qu[i][2][k];
				z1="";
				z2="";
				for (int p=k+1;p<qu[i][1].size();p++)
				{
					z1+=qu[i][1][p];
					z2+=qu[i][2][p];
				}
				if (w1==w2&&z1==z2)
				{
					for (int l=1;l<=n;l++)
					{
						if (x1==s[l][1]&&x2==s[l][2])
						{
							ans[i]++;
						}
					}
				}
			}
			x1="";
			x2="";
		}
	}
	for (int i=1;i<=q;i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
