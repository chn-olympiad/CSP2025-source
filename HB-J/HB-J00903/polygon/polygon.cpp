#include<bits/stdc++.h>
using namespace std;
int a[5001],n,max1,ans=0;
void bfs(int x,int b,int c,int d)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			if(a[i]>a[j])
			{
				max1=a[i];
			}
			else max1=a[j];
		}	
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];

	}
	if(n<=3)
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(i!=j and i!=k and j!=k)
					{
						if(a[i]+a[j]+a[k]>max1*2)
						{
							ans++;
							}
							}
							}
							}
							}
	else
	{
		
	}
	cout<<ans;
	return 0;
}
