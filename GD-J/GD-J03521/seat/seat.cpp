#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e3+9;
int n,m,b[N],c;
pair<int,int> a[N];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n; //reversed
	for(int p=1,i,j=1;p<=m*n;){
		for(i=1;i<=m;i++){
			a[p]={j,i};
			p++;
		}
		j++;
		for(i=m;i>=1;i--){
			a[p]={j,i};
			p++;
		}
		j++;
	}
	for(int i=1;i<=n*m;i++) cin>>b[i];
	c=b[1];
	sort(b+1,b+1+n*m);
	c=b+1+n*m-lower_bound(b+1,b+1+n*m,c);
	cout<<a[c].first<<' '<<a[c].second;
	return 0;
}
