#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100;
int n,m;
int ans;
struct node
{
	int num,id;
}a[N*N+5];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].num,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
//	puts("");
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1)
			ans=i;
	int ansx,ansy;
	ansy=ans/n;
	if(ans%n==0)
	{
		ansy=ans/n;
		if(ansy%2==1)
			ansx=n;
		else
			ansx=1;
	}
	else
	{
		ansx=ans-ansy*n;
//		cout<<ansx<<"\n";
		if((ansy+1)%2==0)
			ansx=n-ansx+1;
		ansy++;
	}
	cout<<ansy<<" "<<ansx<<"\n";
	return 0;
}

