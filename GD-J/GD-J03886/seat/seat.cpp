#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=105,mod=998244353,inf=0x3f3f3f3f;
int n,m,a[MAXN],b[MAXN];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,greater<int>());
	int k=lower_bound(b+1,b+n*m+1,a[1],greater<int>())-b-1;
	cout<<k/n+1<<" "<<(((k/n)&1)?n-k%n:k%n+1);
	return 0;
}

