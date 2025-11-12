#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n][2];
	string p[q][2];
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<n;i++)
	{
		cin>>p[i][0]>>p[i][1];
	}
	for(int i=0;i<q;i++)
	{
		unsigned long long ans=0;
		for(int j=0;j<p[i][0].size();j++)
		{
			for(int k=0;k<n;k++)
			{
				if(p[i][0][j]==a[k][0][0])
				{
					bool flag=1;
					for(int l=1;l<a[k][0].size();l++)
					{
						if(p[i][0][j+l]!=a[k][0][l])
						{
							flag=0;
						}
						if(!flag)
						{
							break;
						}
					}
					if(flag)
					{
						char comp[p[i][0].size()];
						for(int l=0;l<p[i][0].size();l++)
						{
							if(l==j)
							{
								for(int o=0;o<a[k][1].size();o++)
								{
									comp[l+o]=a[k][1][o];
								}
								l+=a[k][1].size()-1;
							}
							else
							{
								comp[l]=p[i][0][l];
							}
						}
						if(comp==p[i][1])
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

