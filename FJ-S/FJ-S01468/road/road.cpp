#include<bits/stdc++.h>
using namespace std;
const int bian=1020;
int n,m,k,a[bian][bian];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	/*for(int i=1;i<=m;i++){
		int l,r,v;
		cin>>l>>r>>v;
		a[l][r]=v;
		a[r][l]=v;
	}*/
	long long ans=0;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		ans+=x;
	}
	cout<<ans;
	return 0;
}
