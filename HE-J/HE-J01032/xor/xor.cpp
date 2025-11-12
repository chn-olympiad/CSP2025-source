#include<bits/stdc++.h>
using namespace std;
int a,b,c[500005],sum,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=a;i++)
	{
		sum=c[i];
		for(int j=i+1;j<=a+1;j++)
		{
			if(sum==b)
			{
				ans++;
				i=j-1;
				break;
			}
			if(j!=a+1) sum=sum^c[j];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 	
}
