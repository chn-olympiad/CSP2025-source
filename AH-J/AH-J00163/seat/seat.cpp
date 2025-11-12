#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int id=(i-1)*n+j;
			cin>>a[id];
			if(a[id]>a[1])cnt++;
		}
	}
	r=cnt/n+1;
	if(r&1)c=1+cnt%n;
	else c=n-cnt%n;
	cout<<r<<" "<<c;
	return 0;
}
