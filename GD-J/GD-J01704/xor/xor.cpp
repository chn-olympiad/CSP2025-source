#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int ans[a+1];
	for(int i=1;i<=a;i++)
	{
		cin>>ans[i];
	}
	int maxx=0;
	for(int i=1;i<=a;i++)
	{
		double sum=0;
		int x=0;
		for(int j=i;j<=a;j++)
		{
			if(sum/x==b) maxx++;
			sum+=ans[j]*1.0;
			x++;
		}
	}
	cout<<maxx;
}
