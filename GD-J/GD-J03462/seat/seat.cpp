#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005;
ll n,m,r,c,tmp,idx,a[maxn];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1],tmp=a[1];
	for(ll i=2;i<=n*m;i++)
	cin>>a[i];
	sort(a+1,a+n*m+1,greater<ll>());
	for(ll i=1;i<=n*m;i++)
	if(a[i]==tmp)
	{
		idx=i;
//		cout<<"id="<<idx<<endl;
		break;
	}
	c=(idx%n==1?idx+n-idx%n:idx)/n,r=(idx%n==0?n:idx%n);
	if(c%2==0)
	r=n-r+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}
