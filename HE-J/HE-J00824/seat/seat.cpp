#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll a[150],n,m,x=1,y=0,k=0;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),cout.tie(0);
	std::cin>>n>>m;
	for(ll i=1;i<=n*m;i++) std::cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	bool f1=0;
	for(ll i=1;i<=n*m;i++)
	{
		++y;
//		cout<<x<<" "<<y<<endl;
		if(y%n==0)
		{
			if(f1) f1=0;
			else f1=1;
		}
		if(a[i]==k)
		{
			std::cout<<x<<" ";
			if(y%n==1)
			{
				if(f1) std::cout<<n;
				else std::cout<<1;
				return 0;
			}
			if(y%n==0)
			{
				if(f1) std::cout<<n;
				else std::cout<<1;
				return 0;
			}
			else
			{
				if(f1) std::cout<<n-y%n;
				else std::cout<<y;
				return 0;
			}
		}
		if(y%n==0) x++;
	}
	return 0;
}
