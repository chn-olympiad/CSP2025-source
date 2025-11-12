#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,a[5005],t[5005],sum,Max,ans;
map <int,int> mp;
map <int,int> mp2;

void f()
{
	for(int i=1;i<=n;i++)
	{
		if(t[i]==1)continue;
		if(n-mp.size()<3)break;
		for(int j=1;j<=n;j++)
		{
			if(!t[j])
			{
				sum+=a[j];
				Max=max(Max,a[j]);
			}
		}
		
		if(sum>2*Max)
		{
			mp2[sum]=1;
		}
		Max=0;
		sum=0;
		t[i]=1;
		mp[i]=1;
		f();
		t[i]=0;
		mp.erase(i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f();
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)continue;
			if(a[i]==a[j])ans++;
		}
	}
	cout<<(mp2.size()+ans)%998244353;
	
} 
