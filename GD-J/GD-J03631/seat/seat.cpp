#include<bits/stdc++.h>
#define int long long
const int N=1e6+10;
using namespace std;
int n,m,ans,a[N];
bool cmp(int p,int q){
	return p>q;
}
signed main(){
	freopen("seat.in","r","std.in");
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i) if(a[i]==x) ans=i;
	int c=(ans-1)/n+1,r=(ans-1)%n+1;
	cout<<c;
	if(c&1) cout<<" "<<r;
	else cout<<" "<<n-r+1;
	freopen("seat.out","w","std.out");
	return 0;
}
