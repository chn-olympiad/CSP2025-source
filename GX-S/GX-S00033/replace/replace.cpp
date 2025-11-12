#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n][2],s2[q][2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>s1[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>s2[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		int cnt=0;
		for(int j=0;j<q;j++)
		{
			if(int(s2[i][0].find(s1[j][0]))!=-1)
			{
				string x="",y="";
				for(int k=0;k<=int(s2[i][0].find(s1[j][0]));k++)
				{
					x+=s2[i][0][k];
				}
				cout<<x<<endl;
				for(int h=s2[i][0].find(s1[j][0])+s1[j][0].length();h<int(s2[i][0].length());h++)
				{
					y+=s2[i][0][h];
				}
				cout<<s2[j][1]<<endl;
				cout<<y<<endl;
				if(x+s1[j][1]+y==s2[i][1])
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
