#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];

bool can(vector<int> a)
{
	int sum=0;
	int maxn=-1;
	for(int i=0;i<a.size();i++)
	{
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	return sum>2*maxn;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	if(n<2)
	{
		cout<<0<<endl;
		return 0;
	}
	else if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<(can({a,b,c}) ? 1 : 0)<<endl;
		return 0;
	}
	else if(n==4)
	{
		int count=0;
		for(int i=1;i<=n;i++){cin>>a[i];}
		if(can({a[1],a[2],a[3]}){count++;}
		if(can({a[1],a[2],a[4]}){count++;}
		if(can({a[1],a[3],a[4]}){count++;}
		if(can({a[2],a[3],a[4]}){count++;}
		if(can({a[1],a[2],a[3],a[4]}){count++;}
		cout<<count<<endl;
		return 0;
	}
	else if(n==5)
	{
		int count=0;
		for(int i=1;i<=n;i++){cin>>a[i];}
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(can({a[i],a[j],a[k]}){count++;}
				}
			}
		}
		
		if(can({a[1],a[2],a[3],a[4]}){count++;}
		if(can({a[1],a[2],a[3],a[5]}){count++;}
		if(can({a[1],a[2],a[4],a[5]}){count++;}
		if(can({a[1],a[3],a[4],a[5]}){count++;}
		if(can({a[2],a[3],a[4],a[5]}){count++;}
		
		if(can({a[1],a[2],a[3],a[4],a[5]}){count++;}
		cout<<count<<endl;
		return 0;
	}
	else if(n==6)
	{
		int count=0;
		for(int i=1;i<=n;i++){cin>>a[i];}
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(can({a[i],a[j],a[k]}){count++;}
				}
			}
		}
		
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+1;j<=n-2;j++)
			{
				for(int k=j+1;k<=n-1;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(can({a[i],a[j],a[k],a[l]}){count++;}
					}
				}
			}
		}
		
		for(int a=1;a<=n-4;a++)
		{
			for(int i=a+1;i<=n-3;i++)
			{
				for(int j=i+1;j<=n-2;j++)
				{
					for(int k=j+1;k<=n-1;k++)
					{
						for(int l=k+1;l<=n;l++)
						{
							if(can({a[i],a[j],a[k],a[l]}){count++;}
						}
					}
				}
			}
		}
		cout<<count<<endl;
		return 0;
	}
	return 0;
}
