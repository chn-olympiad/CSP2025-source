#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n = 0,xq = 0;
		int a[100010][13] = {};
		int c[4][100010] = {};
		int m[100100][4] = {};
		int mn[100100][4] = {};
		int xqc[1000100] = {};
		int sum = 0; 
		xq = 0;
		cin>>n;
		int ban = n/2;
		for(int i = 1;i<=3;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				cin>>a[j][i];
			}	
		}
		int l = 0;
		for(int i= 1;i<=n;i++)
		{
			l++;
			for(int j = 1;j<=3;j++)
			{
			if(a[i][j]>m[l][1])
			{
				m[l][3] = m[l][2];
				mn[l][3] = mn[l][2];
				m[l][2] = m[l][1];
				mn[l][2] = mn[l][1];
				m[l][1] = a[i][j];
				mn[l][1] = j;
			}
			c[mn[l][1]][0]++;
			c[mn[l][i]][j] = l;
			xq+=m[l][1];
			xqc[l] = m[l][1]-m[l][2];
			}
			for(int i = 1;i<=n;i++)
			{
			while(c[i][0]>ban)
			{
				int mic = 0x3f,miv = 0;
				for(int j = 1;j<=n;j++)
				{
					if(xqc[c[i][j]]<mic)
					{
						mic = xqc[c[i][j]];
						miv = c[i][j];
					}
				}
				c[i][0]--;
				c[mn[miv][2]][0]++;
				xq-=m[miv][1];
				xq+=m[miv][2];
			}
			}
		}
		cout<<xq<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
