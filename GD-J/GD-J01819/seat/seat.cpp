#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,m,a[N*N],cnt=1;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		cnt+=(a[i]>a[1]);
	}
	cout<<(cnt-1)/m+1<<' ';
	if(((cnt-1)/m)%2==0) cout<<((cnt-1)%m+1);
	else cout<<(m-(cnt-1)%m);
	return 0;
}
