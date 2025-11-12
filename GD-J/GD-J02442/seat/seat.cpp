#include<bits/stdc++.h>
using namespace std;
const int N=201;
int xr,rn,a[N],rk,n,m;
void solve()
{	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	xr=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==xr)
		{	rk=i;
			break;
		}
	//cout<<rk<<" ";
	int cu=rk/n,md=rk%n;
	if(rk==n*m)
	{	cout<<n<<" "<<m<<"\n";
		return;
	}
	if(rk%n!=0)
		cu++;
	if(cu%2==0&&md!=0)
		md=n-md+1;
	if(md==0)
		if(cu%2==0)
			md+=1;
		else
			md+=n;
	cout<<cu<<" "<<md<<"\n";
}
int main()
{	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}
//DeBruyne rp++
