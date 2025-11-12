#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int t,n,p=-1,u,sum=0;
	int a,b[100010],c,b1[100010];
	cin>>t;
	for(int w=0;w<t;w++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b[i]>>c;
		}
		for(int i=0;i<n;i++)
		{
			for(int q=0;q<n;q++)
			{
				if(b[q]>p)
				{
					p=b[q];
					u=q;
				}
				b1[i]=p;
				b[u]=-1;
			}
		}
		for(int i=0;i<n/2;i++)
		{
			sum+=b1[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
