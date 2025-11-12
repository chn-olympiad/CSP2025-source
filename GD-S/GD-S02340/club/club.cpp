#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+6;
ll t,n;
ll a[N],b[N],c[N];
ll maxn=0;
void f(ll pos,ll na,ll nb,ll nc,ll num)
{
	if(pos>n)
	{
		maxn=max(maxn,num);
		return;
	}
	if(na<n/2) f(pos+1,na+1,nb,nc,num+a[pos]);
	if(nb<n/2) f(pos+1,na,nb+1,nc,num+b[pos]);
	if(nc<n/2) f(pos+1,na,nb,nc+1,num+c[pos]);
	return;
}
void f2(ll pos,ll na,ll nb,ll num)
{
	if(pos>n)
	{
		maxn=max(maxn,num);
		return;
	}
	if(na<n/2) f2(pos+1,na+1,nb,num+a[pos]);
	if(nb<n/2) f2(pos+1,na,nb+1,num+b[pos]);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		maxn=0;
		cin>>n;
		bool fa=1,fab=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0) fa=0,fab=0;
			if(b[i]!=0) fa=0;
		}
		if(fa)
		{
			sort(a+1,a+1+n);
			for(int i=n;i>n/2;i--)
			{
				maxn+=a[i];
			}
			cout<<maxn;
		}
		else if(fab)
		{
			f2(1,0,0,0);
			cout<<maxn<<endl;
		}
		else
		{
			f(1,0,0,0,0);
			cout<<maxn<<endl;
		}
		
	}
	
	
	fclose(stdin);
	fclose(stdout);
	// 罗小黑生日快乐 :) 
	return 0;
}

