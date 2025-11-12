#include<bits/stdc++.h>
using namespace std;
int n=0,a[1000005],b[1000005],c[1000006];int k=0,sum;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			sum++;
			c[i]++;
		}
	 } 
	 b[1]=a[1];
	 for(int i=2;i<=n;i++)
	 {
	 	
	 	
	 	b[i]=a[i-1]^a[i];
	 }
	 for(int i=2;i<=n-1;i++)
{
int h;
h=a[i-1]^a[i];
	for(int j=i;j<=n;j++)
	{
		if(h==k)
		{
			sum++;
			for(int w=i;w<=j;w++)
			{
				c[w]++;
			}
			i=j+1;
		}
		else
		{
			h^a[j+1] ;
		}
	}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<" ";
	}
		return 0;
}

