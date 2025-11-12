#include<iostream>
using namespace std;
int a[500010],book[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i=1,f=0,f1=0,sum=0;
	cin>>n>>k;
	for(;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		f=1;
		if(a[i]>1)
		f1=1;
	}
	if(k==0&&f==0)
	{
		cout<<n/2;
		return 0;
	}//1
	if(k==0&&f1==0)
	{
		for(i=1;i<n;i++)
		{
			if(a[i]==0)
			sum++;
			if(a[i]==1&&a[i+1]==1)
			{
				sum++;
				i++;
			}
		}
		cout<<sum;
		return 0;
	}
	if(k==1&&f1==0)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]==1)
			sum++;
		}
		cout<<sum;
		return 0;
	}//2,3,4,5
	
	
	for(i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			sum++;
			book[i]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			int c=a[i],j=i+1;
			while(book[j]==0)
			{
				c=c^a[j];
				if(c==k)
				{
					for(;j>=i;j--)
					book[j]=1;
					sum++;
					break;
				}
				j++;
			}
		}
	}
	cout<<sum;
	return 0;
}
