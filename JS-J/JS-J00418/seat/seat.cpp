#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int a[N],b[N],n,m,x,y;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int c = n * m;
	for(int i = 1 ; i <= c ; i ++)
		cin >> a[i],b[a[i]] ++;
	for(int i = 100 ; i >= 1 ; i --)
		b[i] += b[i + 1];
	x = (b[a[1]] - 1) / n + 1,y = (b[a[1]] - 1) % n;
	cout << x << " " << (x & 1 ? y + 1 : n - y);
	return 0;
}