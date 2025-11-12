#include<bits/stdc++.h>
using namespace std;
#define int long long //<------------------------
int n,m;
struct node
{
	int x;
	bool flag;
}a[101];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x;
	a[1].flag=1;
	sort(a+1,a+1+n*m,cmp);
	int flag=1;
	bool zx=1;
	int cnt=1;
	int i=1,j=1;
	while(1)
	{
		if(a[cnt].flag) return cout<<j<<" "<<i,0;
		if((i==n||i==1)&&zx==0) 
		{
			zx=1;
			j++;
			flag*=-1;
			cnt++;
			continue;
		}
		cnt++;
		zx=0;
		i+=flag;
	}
	return 0;
}
/*

shen shou bao you

*/
