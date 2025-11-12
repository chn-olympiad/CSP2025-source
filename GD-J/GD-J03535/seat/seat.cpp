#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,mod=1e9+7;
struct node
{
	int x,id;
}a[110];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+s+1,cmp);
	int f=0;
	for(int i=1;i<=s;i++) if(a[i].id==1) f=i;
	int c=(f-1)/n+1,r;
	f-=n*(c-1);
	if(c%2==0) r=n-f+1;
	else r=f;
	cout<<c<<' '<<r;
	return 0;
}
/*
100pts
怎么没大样例
预估橙
*/ 