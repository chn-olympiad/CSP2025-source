#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,cnt=0;cin>>x;
	for(int i=1;i<n*m;i++){
		int q;scanf("%lld",&q);
		if(q>x)cnt++;
	}
	cout<<cnt/n+1<<' ';
	int els=cnt%n+1;
	if((cnt/n)%2==0)cout<<els;
	else cout<<n-els+1;
}
