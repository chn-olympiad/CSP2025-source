#include<bits/stdc++.h>
using namespace std;
int n,a[500010],ans=0,zero=0,one=0,f[500010],k;
queue<int>q,q1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{		
		scanf("%d",&a[i]);	
		if(a[i]==0) zero++;
		if(a[i]==1) one++;
	}
	if(one==n) 
	{
		if(k==1)
		cout<<n;
		if(k==0)
		cout<<n/2;
		return 0;
	}
	else if(zero==n)
	{
		if(k==0)
		cout<<n;
		else cout<<0;
		return 0;
	}
	else if(zero+one==n)
	{
		
		if(k==0)
		{
			int p=0;
			for(int i=1;i<=n;i++)
			{
				int x=0;
				while(1)
				{
					if(a[i]==1)
					{
						x++;
						i++;
						if(x==2)
						{
							x=0;
							p++;
						}
					}
					else break;
				}
			}
			cout<<zero+p;
		}		
		if(k==1)
		{
			cout<<one;
		}		
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int p=0;
		for(int j=i;j<=n;j++)
		{
			p=p^a[j];
			if(p==k)
			{
				f[i]=j;
				break;
			}
		}
	}
	q1.push(0);q.push(0);
	while(q.size())
	{
		int m=q.front();q.pop();
		int p=q1.front();q1.pop();
		ans=max(m,ans);
		for(int i=p+1;i<=n;i++)
		{
			if(f[i]!=0&&i<n)
			{
				q.push(m+1);
				q1.push(f[i]);
			}
		}
	}
	cout<<ans;
}
