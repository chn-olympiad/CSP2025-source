#include<bits/stdc++.h> 
//#define int long long
using namespace std;
const int maxn=105;
int n,m,a[maxn];
int s=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=1;i<=n*m;i++)if(a[i]>=a[1])s++;
	int y=(s-1)/n+1;
	cout<<y<<' ';
	int t=s%n;
	if(t==0)t=n;
	if(y&1)cout<<t;
	else cout<<(n-t+1);
	return 0;
}
