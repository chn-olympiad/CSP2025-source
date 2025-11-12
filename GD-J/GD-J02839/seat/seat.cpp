#include<bits/stdc++.h>
using namespace std;
int n,m,w;
struct node{int x,y;}a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,[](node x,node y){return x.x>y.x;});
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].y==1)w=i;
	}
	cout<<(w+n-1)/n<<' ';
	if((w+n-1)/n&1)cout<<w-(w-1)/n*n;
	else cout<<(w+n-1)/n*n-w+1;
	return 0;
}
