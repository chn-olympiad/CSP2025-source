#include<iostream>
using namespace std;
int n,k,a[500000],num=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			num++;
			a[i]=-1;
		}
	}
	for(int i=0,s;i<n;i++)
	{
		if(a[i]==-1) continue;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]==-1) continue;
			s=i;
			for(int z=i+1;z<=j;z++)
			{
				if(a[z]==-1)
				{
					break;
				}
				else
				{
					s=s^a[z];
					
				}
			}
			if(s==k)
			{
				num++;
				for(int z=i;z<=j;z++)
				{
					a[z]=-1;
				}
			}
		}
	}
	cout<<num<<endl;
	return 0;
} 
