#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int T,n,m;
struct seat
{
	int x,id;
}a[10005];
bool cmp(seat x,seat y)
{
	return x.x>y.x;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n*m) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	rep(i,1,n*m)
	{
		if(a[i].id==1)
		{
			int pos=i;
			// cout<<pos<<" ";
			int lie=pos/n+1;
			if(pos%n==0) lie--;
			// cout<<lie<<" ";
			int hang=pos%n;
			// cout<<hang<<'\n';
			if(hang==0) hang=n;
			if(lie&1) cout<<lie<<" "<<hang;
			else cout<<lie<<" "<<m-hang+1;
			break;
		}
	}
	return 0;
}
