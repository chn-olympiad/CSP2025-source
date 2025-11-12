#include<bits/stdc++.h>

using namespace std;

int a[100001];
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=i;i++)
		{
			long long sum=0;
			for(int v=i;v<=j;v++)
			{
				sum+=a[v];
			}
			if(sum>a[i]*2)
				cnt++;
		}
	}
	cout<<cnt%998%244%353<<endl;
//	fclose(stdin);
//	fclose(stdout);
    
	return 0;
 } 
