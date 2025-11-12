#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	string str1[n][2],str2[m][2];
	for(int i=0;i<n;++i)
	{
		cin>>str1[i][0]>>str1[i][1]; 
	}
	for(int i=0;i<m;++i)
	{
		cin>>str2[i][0]>>str2[i][1];
	}
	for(int x=0;x<m;++x)
	{
	int y=str2[x][0].size(),z=0;
	string str4;
	for(int i=0;i<y;++i)
	{
		int s=y-i+1,j=1; 
		for(;j<s;++j)
		{
			for(int k=0;k<n;++k)
			{
				string str3=str2[x][0].substr(i,j);
				if(str1[k][0]==str3)
				{
					str4+=str1[k][1];
					i+=j-1;
					++z;
				}
			}
		}
		if(str4==str2[x][1])
		{
			cout<<z<<endl;
			break;
		}
		if(j==s)
		{
			cout<<"0"<<endl;
			break;
		}
	}
	}
	
	return 0;
}
