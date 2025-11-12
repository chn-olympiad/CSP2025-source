#include<bits/stdc++.h>
using namespace std;
bool a1[10];
string c,b;
struct a
{
	string e;
}f[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(int i=0;i<c.size();i++)
	{
		if(c[i]-'0'>=0 && c[i]-'0'<=9)
		{
			a1[c[i]-'0']=1;
			f[c[i]-'0'].e=f[c[i]-'0'].e+c[i];
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a1[i]!=0)
		{
			b=b+f[i].e;
			a1[i]=0; 
		}
	}
	cout<<b;
	return 0;
}
