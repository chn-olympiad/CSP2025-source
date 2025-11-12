#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++)if(a[i]<a[1])k++;
	k=n*m-k;
	cout<<(k-1)/n+1<<" "<<((((k-1)/n+1)&1)?(k-(k-1)/n*n):(n-k+(k-1)/n*n+1));
	return 0;
}
