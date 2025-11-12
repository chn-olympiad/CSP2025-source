#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n][2];
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	string t[q][2];
	for(int i=0;i<q;i++)
	{
		cin>>t[i][0]>>t[i][1];
	}
	int z[q]={};
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<n;j++)
		{
			string t0,t1;
			t0=t[i][0];
			t1=t[i][1];
			while(s[j][0].size()<=t0.size()&&s[j][1].size()<=t1.size())
			{
				int a0=t0.find(s[j][0]);
				int a1=t1.find(s[j][1]);
				if(a0!=-1&&a1!=-1&&a0==a1)
				{
					t0.erase(a0,s[j][0].size());
					t1.erase(a1,s[j][1].size());
					if(t0==t1)
					{
						z[i]++;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		cout<<z[i]<<endl;
	}
	return 0;
}
