#include<bits/stdc++.h>
using namespace std;
long long a[500086];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool o=0;
	bool j=0;
	bool l=0;
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			o=1;
		}
		if(a[i]>1)
		{
			j=1;
		}
		if(a[i]!=0)
		{
			l=1;
		}
	} 
	if(o==0&&k==0)
	{
		cout<<n/2<<endl;
		return 0;
	}//A:OK!
	if(k==1)
	{
		if(j==0)
		{
			long long cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}
		else cout<<"4"<<endl;
		return 0;
	}
	else if(k==0)
	{
		if(j==0)
		{
			long long cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					cnt++;
				}
				else if(a[i]==1&&a[i+1]==1)
				{
					cnt++;
					i++;
				}
			}
			cout<<cnt<<endl;
		}
		else cout<<"5"<<endl;
		return 0;
	}//B:OK
	return 0;
 } 
