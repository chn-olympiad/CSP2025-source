#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],g[maxn],n_s;
struct node
{
	int st,en;
}s[maxn];
bool cmp(node x,node y)
{
	if(x.en==y.en) return x.st<y.st;
	return x.en<y.en;
}
bool oA,oB,oC;
bool op[maxn];
bool check(int x)
{
	int num=0,num_ans=0;
	for(int i=1;i<=n;i++)
	{
		if((g[i]^g[num])==k) 
		{
			num=i;
			num_ans++;
		}
		if(num_ans>=x) return 1;
	}
	return 0;
}
void A()//特殊性质A 
{
	cout<<n/2<<endl;
}
void B()//特殊性质B 
{
	if(k==0)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) ans++;
			else if(a[i]==1&&a[i-1]==1&&op[i-1]==0)
			{
				op[i]=op[i-1]=1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	if(k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans++;
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) oA=1;
		if(a[i]>1) oB=1;
		if(a[i]>255) oC=1;
	}
	g[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		g[i]=g[i-1]^a[i];
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++) 
			for(int j=i;j<=n;j++)
			{
				if((g[j]^g[i-1])==k)
				{
					s[++n_s].st=i,s[n_s].en=j;
				}
			}
		sort(s+1,s+n_s+1,cmp);
		int ans=0,num1=0;
		for(int i=1;i<=n_s;i++)
		{
			if(s[i].st>num1)
			{
				ans++;
				num1=s[i].en;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(oA==0)
	{
		A();
		return 0;
	}
	if(oB==0)
	{
		B();
		return 0;
	}
	int l=0,r=n,mid;
	while(l<r)
	{
		//cout<<l<<' '<<r<<endl;
		mid=(l+r+1)/2;
		if(check(mid)==1) l=mid;
		else r=mid-1;
	}
	cout<<(l+r)/2<<endl;
	return 0;
}
/*
5 2
2 5 0 2 1
*/
