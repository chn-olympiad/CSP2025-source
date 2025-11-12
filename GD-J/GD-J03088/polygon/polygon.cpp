#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
const int N=5e3+5;
const int V=5e4+5;
int n,a[N],ans;
int S,s[V]={1};
int find(int x)
{
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]<x)
			l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}
int qpow(int a,int x)
{
	int s=1;
	for(;x;x>>=1,a=(a*a)%p)
		if(x&1)s=(s*a)%p;
	return s;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],S+=a[i];
	sort(a+1,a+1+n);
	if(n<=20)//O(n2^n) #1-10
	{
		for(int j=1;j<(1<<n);j++)
		{
			int sum=0,cnt=0,pid=0;
			for(int i=1;i<=n;i++)
				if((j>>(i-1))&1)
					sum+=a[i],
					cnt++,
					pid=i;
			if(cnt<2)continue;
			if(sum>a[n])ans+=n-pid;
			else ans+=find(sum)-pid;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(a[n]<=1)//O(nlogn) #15-20
	{
		for(int i=3;i<=n;i++,ans%=p)
			ans+=qpow(2,i-1)-(i-1)-1;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)//O(n^2V) #11-14
	{
		for(int j=S;j>a[i];j--)
			ans+=s[j],ans%=p;
		for(int j=S-a[i];j>=0;j--)
			s[j+a[i]]+=s[j],s[j+a[i]]%=p;
	}
	cout<<ans<<endl;
	return 0;
}
