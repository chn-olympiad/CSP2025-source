#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string g;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if((s[i]>='1' and s[i]<='9') or s[i]=='0')
		{
			g+=s[i];
		}
	}
	for(int j=1;j<=10;j++)
	for(int i=0;i<g.size();i++)
	{
		if(j==1 and g[i]=='9')
		cout<<g[i];
		if(j==2 and g[i]=='8')
		cout<<g[i];
		if(j==3 and g[i]=='7')
		cout<<g[i];
		if(j==4 and g[i]=='6')
		cout<<g[i];
		if(j==5 and g[i]=='5')
		cout<<g[i];
		if(j==6 and g[i]=='4')
		cout<<g[i];
		if(j==7 and g[i]=='3')
		cout<<g[i];
		if(j==8 and g[i]=='2')
		cout<<g[i];
		if(j==9 and g[i]=='1')
		cout<<g[i];
		if(j==10 and g[i]=='0')
		cout<<g[i];
	}
	return 0;
}
