#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+7;
int n,k,cnt=0;
int a[N],arr[N],f[N];
int rra(int l,int r)
{
	l--;
	return (~(arr[r]&arr[l])&(arr[r]|arr[l]));
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	bool fa=1,fb=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0) fa=fb=0;
		if(a[i]!=1) fa=0;
	}
	arr[1]=a[1];
	for(int i=2;i<=n;i++) arr[i]=arr[i-1]^a[i];
	if(fa)
	{
		cout<<int(n/2);
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==k) cnt+=1;
	if(fb)
	{
		fb=0;
		if(k==0)
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=k) cnt+=fb,fb=!fb;
				else fb=0;
			}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k) continue;
		for(int j=1;j<=n-i+1;j++)
		{
			if(a[i+j-1]==k) break;
			f[j]=max(f[j],f[j]+(rra(i,i+j-1)==k?1:0));
		}
	}
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++)
		maxn=max(maxn,f[i]);
	cout<<cnt+maxn;
	return 0;
}
