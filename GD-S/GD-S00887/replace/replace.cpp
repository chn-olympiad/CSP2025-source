#include<bits/stdc++.h>
using namespace std;
string a[210000][2];
string b[210000][2];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<q;i++)
	{
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=0;i<q;i++)
	{
		int ans=0;
		for(int j=0;j<int(b[i][0].size());j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int o=j;o<int(a[k][0].size());o++)
				{
					if(a[k][0][o-j]!=b[i][0][o]||a[k][1][o-j]!=b[i][1][o])
					{
						break;
					}
					if(o==int(a[k][0].size())-1)
					{
						bool m=true;
						for(int z=0;z<int(b[i][0].size());z++)
						{
							if(j==0&&int(b[i][0].size())==int(a[k][0].size()))
							{
								ans++;
								break; 
							}
							if((z<j||z>=int(a[k][0].size()))&&b[i][0][z]!=b[i][1][z])
							{
								m=false;
							}
						}
						if(m)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
