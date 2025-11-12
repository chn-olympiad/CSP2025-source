#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=15;
int a[105];
int n,m,cnt=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int c=(cnt+n-1)/n,r=cnt%n;
	if(r==0) r=n;
	if(c%2==0) r=n-r+1;
	cout<<c<<' '<<r;
	return 0;
}
