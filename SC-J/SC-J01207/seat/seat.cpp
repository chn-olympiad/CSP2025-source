#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int R,a;
int cnt;
int i_,j_;

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	cin>>R;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a;
		cnt+=(a>R);
	}
	cnt++;
	j_=ceil((double)cnt/n);
	i_=(j_%2==1)?((cnt-1)%n+1):(n-(cnt-1)%n);
	cout<<j_<<" "<<i_;
	
	return 0;
}