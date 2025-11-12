#include <bits/stdc++.h>
using namespace std;

int a[100005];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int kfg = a[1], k = 0;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++)
		if(kfg==a[i]){
			k=i;
			break;
		}
	if((k-1)/n%2==0)
		cout << (k-1)/n+1 << " " << (k-1)%n+1;
	else
		cout << (k-1)/n+1 << " " << n-(k-1)%n;
}
