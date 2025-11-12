#include<bits/stdc++.h>
using namespace std;
string s;
int v[1000005];
int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') v[s[i]-='0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=v[i];j++) printf("%d",i);
	}
	return 0; 
}
