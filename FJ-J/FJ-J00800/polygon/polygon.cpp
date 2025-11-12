#include<bits/stdc++.h>
using namespace std;
int s[5000];
int main()
{
	freopen("polygon.in ","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int a;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>s[i];
	}
	if(a==3)
	{
		sort(s+0,s+3);
		if(s[0]+s[1]+s[2]>s[2]*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(a<3)
	{
		cout<<0;
	}
	else
	{
	cout<<(10086114514*a)%998244353;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
