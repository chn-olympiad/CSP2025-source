#include<bits/stdc++.h>
using namespace std;
long long a[500005],maxn=-1,n,ans,k;
int f(int cnt)
{
	int sum=a[cnt];
	for(int i=cnt+1;i<=n;i++)
	{
		sum=sum^a[i];
		if(sum>k)break;
		if(sum==k)return i;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		ans=0;
		for(int j=i;j<=n;j++)
		{
			if(j<=flag||a[j]>k)continue;
			if(a[j]==k)ans++;
			else
			{
				int x=f(j);
				if(!x)continue;
				else 
				{
					flag=x;	
					ans++;
				}
			}
		}	
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}