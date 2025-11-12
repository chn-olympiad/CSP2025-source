#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
struct node
{int v,p;}a[N];
bool cmp(node a,node b)
{return a.v>b.v;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].v,a[i].p=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].p==1)
		{
			int r=(i-1)/n+1,c=i-(r-1)*m;
			if(r&1)cout<<r<<" "<<c<<endl;
			else cout<<r<<" "<<m-c+1<<endl;
		}
	return 0;
}
