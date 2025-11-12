#include<bits/stdc++.h>
using namespace std;
int n,m;
int f,a;
int cnt = 1;
signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>f;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a;
		if(a>f)
			cnt++;
	}
	int c = (cnt + n - 1) / n;
	cnt %= (n<<1);
	int r;
	if(1<=cnt&&cnt<=n)
		r = cnt;
	else	r = (((n<<1)|1) - cnt) % (n<<1);
	cout<<c<<" "<<r<<endl;
	return 0;
} 
