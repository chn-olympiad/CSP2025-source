#include<bits/stdc++.h>
#define int long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m;
struct _{
	int val,id;
}a[120];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n*m)scanf("%lld",&a[i].val),a[i].id=i;
	sort(a+1,a+n*m+1,[](_ x,_ y){return x.val>y.val;});
	int x=1,y=1,i=1;
	while(a[i].id!=1)
	{
		if(y%2==1&&x==n)y++;
		else if(y%2==0&&x==1)y++;
		else if(y%2==1)x++;
		else x--;
		i++;
	}
	cout<<y<<" "<<x;
	return 0;
}
