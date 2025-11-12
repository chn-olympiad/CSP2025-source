#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,ans=1,a[11451400];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;++i){
		cin>>a[i];
		if(a[i]>a[1]) ++ans;
	}
	cout<<(ans-1)/n+1<<" ";
	if(((ans-1)/n+1)%2==1) cout<<(ans-1)%n+1;
	else cout<<n-(ans-1)%n;
}
