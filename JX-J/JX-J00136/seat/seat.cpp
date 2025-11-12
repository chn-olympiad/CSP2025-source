/*
./compile seat a
./seat
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define allof(o) (o).begin(),(o).end()
using namespace std;
pii a[105],b;
int n,m;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].first,a[i].second=i;
	b=a[1];
	sort(a+1,a+n*m+1,greater<pii>());
	int id=find(a+1,a+n*m+1,b)-a;
	int x=1;
	int y=1;
	while(--id)
	{
// cerr<<x<<" "<<y<<'\n';
		if((x&1)&&(y==n)||(!(x&1))&&(y==1))
			x++;
		else if(x&1)y++;
		else y--;
	}
	cout<<x<<" "<<y<<'\n';
	return 0;
}