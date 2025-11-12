#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int n,m,a[1005],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=n*m;i++) if(a[i]>=a[1]) cnt++; 
	int ans1=(cnt+n-1)/n;
	cout<<ans1<<" ";
	int ans2=(cnt%n==0?n:cnt%n);
	cout<<(ans1%2?ans2:n-ans2+1);
	return 0;
}
