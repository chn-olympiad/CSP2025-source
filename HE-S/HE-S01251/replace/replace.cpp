#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a[n],b[n],c[m],d[m],btcA,btcB;
	int bt_w,bt_o;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>c[i]>>d[i];
	}
	for(int i=0;i<m;i++) 
	{
		bt_o=-1;
		bt_w=-1;
		int sum=0;
		for(int j=0;j<c[i].size();j++)
		{
			if(c[i][j]!=d[i][j])
			{
				if(bt_o==-1)
				{
					bt_o=j;
				}
				bt_w=j;
			}
		}
		for(int j=bt_o;j<=bt_w;j++)
		{
			btcA+=c[i][j];
			btcB+=d[i][j];
		}
		for(int j=0;j<n;j++)
		{
			if(btcA==a[j]&&btcB==b[j])
			{
				sum++;
			}
			if(a[j]==c[j]&&b[j]==d[j])
			{
				sum++;
			}//878888888888888888888888787787878787788778
		}
		for(int j=0;j<=bt_o;j++)
		{
			for(int fr=0;fr<n;fr++)
			{
				if(a[fr][0]==c[i][j]&&b[fr][0]==d[i][j])
				{
					for(int fe=1;fe<a[fr].size();fe++)
					{
						if(a[fr][fe]!=c[i][j+fe]||b[fr][fe]!=d[i][j+fe])
						{
							if(fr+fe>=bt_w)
							{
								sum++;
							}
							else{
								break;
							}
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
