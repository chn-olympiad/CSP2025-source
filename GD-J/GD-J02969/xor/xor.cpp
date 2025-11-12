#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int flag=0,p;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==k)
			{
//				cout<<i<<" "<<j-1<<endl;
				sum++;
				break;
			}
			int m=a[i] xor a[j];
			if(m==k)
			{
//				cout<<i<<" "<<j<<endl;
				p=j;
				flag=1;
				sum++;
				break;
			}
		}
		if(flag)i=p;
	}
	cout<<sum;
	return 0;
}
