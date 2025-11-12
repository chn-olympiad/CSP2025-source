#include <iostream>
#define stop() getchar(),getchar();
using namespace std;
namespace sub1
{
	int n,k,mmax=-1;
	const int N=5e5+5,lN=10e3+5;
	int a[N]={0};
	int specialA()
	{
		cout<<0;
		exit(0);
	}
	int dfs(int l=1,int val=0)
	{
		if(l==n)
		{
			if(mmax<val)
				mmax=val;
			return 0;
		}
		bool f=1;
		for(int i=l;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int t=a[i];
				for(int l=i+1;l<=j;l++)
				{
					t^=a[l];
				}
				if(t==k)
				{
					dfs(i+j+1,val+1);
				}
			}
		}
		if(f)
		{
			if(mmax<val)
				mmax=val;
			return 0;
		}
		return val;
	}
	int main()
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[N];
		bool f=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=1)
			{
				f=0;
				break;
			}
		if(f && k==0)specialA();
		dfs();
		cout<<mmax;
		exit(0);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	sub1::main();
	return 0;
}
