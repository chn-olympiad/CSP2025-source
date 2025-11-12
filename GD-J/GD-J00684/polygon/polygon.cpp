#include<bits/stdc++.h>
using namespace std;
long long n,m,g,d,e,w,a[1000000],bj,ans,sum,mid;
void dfs(long long now,long long h,long long gs)
{
	if(h>2*a[now]&&gs>=3)
	{
		ans++;
		ans%=998244353;
	}
	for(int i=now+1;i<=n;i++)
	{
		dfs(i,h+a[i],gs+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bj=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)bj=0;
	}
	if(bj==0)
	{
		sort(a+1,a+n+1);
		dfs(0,0,0);
	}
	else
	{
		for(int i=3;i<n;i++)
		{
			mid=n;
			m=i;
			for(int j=n-1,k=1,p=n-m;j>=1;j--,k++,p--)
			{
				mid*=j;
				if(k<=m)mid/=k;
				if(p>0)mid/=p;
				if(k>m&p<=0)
				{
					mid%=998244353;
				}
			}
			ans+=mid;
			ans%=998244353; 
		}
		ans+=1;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
 
