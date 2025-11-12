#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
const int N=2e6+10;
int n,m,x,a,ans1,ans2,cnt=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;++i) cin>>x,cnt+=(x>a);
	ans1=(cnt+n-1)/n,ans2=(ans1&1?(cnt-1)%n+1:n-(cnt-1)%n);
	cout<<ans1<<' '<<ans2;
	return 0;
}
