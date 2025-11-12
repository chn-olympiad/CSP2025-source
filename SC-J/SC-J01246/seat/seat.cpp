//seat
#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;

int n,m,ans;
int a[N][N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			if(a[i][j]>a[1][1]) ans++;
		}
	}
	int h=ans/n;
	ans-=h*n;
	cout<<h+1<<" ";
	if(h&1) cout<<n-ans;
	else cout<<ans+1;
	return 0;
}