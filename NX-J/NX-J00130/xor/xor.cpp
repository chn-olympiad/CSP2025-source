#include <bits/stdc++.h>
using namespace std;

long long a[1000000];
int b[1000000];

/*long long to2(int n)
{
	stack<int> s;
	while(n>1)
	{
		s.push(n%2);
		n/=2;
	}
	long long ans=0;
	if(n==1)
	{
		ans+=1;
	}
	while(s.size())
	{
		if(s.top()==1)
		{
			ans*=10;
			ans+=1;
			s.pop();
			}
		else
		{
			ans*=10;
			s.pop();
		}
	}
    return ans;
}*/

long long xor1(int a,int b)
{
	return a^b;
} 
int s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    for(int i=1;i<=n;i++)
    {
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				if(a[i]==k&&b[i]==0)
				{
					s++;
					b[i]=1;
				}
			}
			else
			{
				int x=0,f=0;
				for(int l=i;l<=j;l++)
				{
					if(b[l]==1)
					{
						f=1;
					}
					x=xor1(x,a[l]);
				}
				if(x==k&&f==0)
				{
					s++;
					for(int l=i;l<=j;l++)
				{
					b[l]=1;
				}
				}
			}
		}
	}
	cout<<s;	
	return 0;
}
