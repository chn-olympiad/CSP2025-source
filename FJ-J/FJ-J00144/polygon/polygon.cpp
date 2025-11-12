#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll l=998244353;
ll n,a[5005],ans;
struct Node{
	ll maxn;
	ll sumn;
}h;
ll f(ll k,ll j)
{
	if(j==0)
	{
		if(h.sumn>h.maxn*2)return 1;
		else return 0;
	}
	int sum=0;
	int maxm=h.maxn;
	for(int i=k+1;i<=n-j+1;i++)
	{
		h.maxn=max(h.maxn,a[i]);
		h.sumn+=a[i];
		sum+=f(i,j-1);
		h.maxn=maxm;
		h.sumn-=a[i];
	}
	return sum%l;
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
	for(int i=3;i<=n;i++)
	{
		h={0,0};
		ans+=f(0,i);
	}
	ans%=l;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

