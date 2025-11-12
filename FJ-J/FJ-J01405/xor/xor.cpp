#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<1;
		return 0;
	}
	int num=0;
	for(int l=1;l<=n;l++)
	{
		int p=a[l];
		for(int r=l;r<=n+1;r++)
		{
			if(r==n+1)
			{
				if(p==k)
				{
					//cout<<"p:"<<p<<endl; 
					//cout<<"l:"<<l<<"  r:"<<r<<endl<<endl;
					num++;
				} 
				break;
			}
			if(p==k)
			{
				//cout<<"p:"<<p<<endl; 
				//cout<<"l:"<<l<<"  r:"<<r<<endl<<endl;
				num++;
			} 
			p^=a[r];
		}
	}
	cout<<num;
	return 0;
}
