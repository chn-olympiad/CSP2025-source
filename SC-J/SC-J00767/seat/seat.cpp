#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a1,cnt;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a1;
	cnt=1;
	for(int i=2;i<=n*m;i++)
	{
		int now;
		cin>>now;
		if(now>a1)	cnt++;
	}
	if((cnt-1)%(2*n)+1<=n)	cout<<(cnt+n-1)/n<<" "<<(cnt-1)%(2*n)+1<<"\n";
	else				cout<<(cnt+n-1)/n<<" "<<(2*n-((cnt-1)%(2*n)+1)+1)<<"\n";
	return 0;
}