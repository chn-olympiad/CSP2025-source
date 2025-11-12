#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 110;
int a[N];
int n,m;
bool cmp(int x,int y) {return x > y;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int len = n * m;
	for(int i=1;i<=len;i++)
		cin>>a[i];
	int tmp = a[1],ix;
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++)
		if(a[i] == tmp) {ix = i;break;}
	int x=1,y=1,xi=1;ix--;
	while(ix)
	{
		x += xi;ix--;
		if(x == n+1 || x == 0)
		{
			x -= xi;y++;
			xi *= -1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}