#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b);
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100010],x,max[100010]=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<s.size();j++)
		{
			if(s[j]>='0'||s[j]<='9')
			{
				x=s[j]-'0';
			}
			if(x>=max[i]-1)
			{
				max[i]=x;
			}
		}
		cout<<x;
		x=0;
		
	}
	return 0;
 } 