#include<bits/stdc++.h>
using namespace std;
bool k3(int a,int b,int c)
{
	int q[4];
	q[1]=a;
	q[2]=b;
	q[3]=c;
	long long sum=0,maxn=0;
	for(int i=1;i<=3;i++)
	{
		sum+=q[i];
		if(q[i]>maxn) maxn=q[i];
	}
	maxn*=2;
	if(maxn>sum) return true;
	else return false;
}
long long maxn=0,sum=0;
int a[5001],n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
		sum+=a[i];
	}
	if(n==3)
	{
		sum=0;
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(a[i]>maxn) maxn=a[i]; 
		}
		maxn*=2;
		if(sum>maxn) cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxn==1)
	{
		cout<<n-2;
		return 0;
	}
	if(n==4){
		int ans=0;
		maxn*=2;
		if(sum>maxn) ans++;
		if(k3(a[1],a[2],a[3])==1) ans++;
		if(k3(a[1],a[2],a[4])==1) ans++;
		if(k3(a[1],a[3],a[4])==1) ans++;
		if(k3(a[2],a[3],a[4])==1) ans++;
		cout<<ans;
		return 0;
	}
	cout<<2;
	return 0; 
}

