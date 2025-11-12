#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],xr,xid;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xr){
			xid=i;
			break;
		}
	}
	int k=1,c=1,r=1;
	while(1){
		if(k==xid) break;
		k++;
		if(c%2==1){
			if(r<n) r++;
			else c++;
		}else{
			if(r>1) r--;
			else c++;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
