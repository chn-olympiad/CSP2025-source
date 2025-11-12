#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],ans=0,s[5010];
queue<int>q1,q2;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{		
		scanf("%d",&a[i]);
	}	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{		
		s[i]=s[i-1]+a[i];
	}	
	for(int i=3;i<=n;i++)
	{
		if(s[i-1]<=a[i]) continue;
		q1.push(s[i-1]);
		q2.push(0);
		ans++;
		while(q1.size())
		{
			int m=q1.front();
			int p=q2.front();
			q1.pop();q2.pop();
			for(int j=p+1;j<i;j++)
			{
				if(m-a[j]>a[i])
				{
					if(j<i-1)
					{
						q1.push(m-a[j]);
						q2.push(j);
					}					
					ans=(ans+1)%mod;
				}				
			}
		}
	}
	printf("%d",ans);
}
