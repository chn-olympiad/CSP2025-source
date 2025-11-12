#include<bits/stdc++.h>
using namespace std;
int c[5000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a;
	int b;
	int ans=0;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		cin>>c[i];
	}
	if(b==0)
	{
		for(int i=0;i<a;i++)
		{
			if(c[i]==0)
			{
				ans++;
			}
		}
	}
	else
	{
		for(int i=0;i<a;i++)
		{
			if(c[i]==1)
			{
				ans++;
			}
		}
	}
	//I don`t know how to do TAT 
	cout<<ans<<endl;
	return 0;
} 