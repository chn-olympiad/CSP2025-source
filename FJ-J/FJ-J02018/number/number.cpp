#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cmp(int x,int y)
{
	return y<x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int z=sizeof(s);
	int y=1;
	for(int i=0;i<=z;i++)
	{
		if(s[i]>='0'&&a[i]<='9')
		{
			if(s[i]>='A'&&s[i]<='z')
			{
				continue;
			}
			a[y]=s[i]-'0';
			y++;
		}
		
	}
	sort(a+1,a+y,cmp);
	for(int i=1;i<=y-1;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
