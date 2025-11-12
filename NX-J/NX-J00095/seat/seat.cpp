#include<bits/stdc++.h>
using namespace std;
int sum=0,num=0,x=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10001];
	for(int i=1;i<=n+m;i++)
	{
		cin>>a[i];
		sum=a[0];
	}
	for(int i=1;i<=n+m;i++)
	{
		if(a[i]>sum) num++;
	}
	if(num<=n) cout<<1<<" "<<num+1;
	else if(num>n*m-n) cout<<m<<" "<<n;
	else
	{
		for(int i=1;i<=m-1;i++)
		{		
			for(int j=1;j<=n;j++)
			{
				if(num==(m-i)*n+j) cout<<(m-i+1)<<" "<<j-n;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
