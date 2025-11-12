#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=201;
int a[N], b[101];
bool cmp(int x, int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.ans", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1], y;
	sort(a+1, a+n*m+1, cmp);
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			y=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
		b[i]=i;
	for(int i=1;i<=n;i++)
		b[i+n]=n-i+1; 
	cout<<ceil((double)(((double)(y))/((double)(n))))<<" "<<b[y%(n*2)]; 
	return 0;
}

