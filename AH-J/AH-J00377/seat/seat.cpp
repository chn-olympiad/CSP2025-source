#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],xr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n=hang m=lie
	for(int i=1;i<=n*m;i++)cin>>a[i];
	xr=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int r=1,c=1,cnt=0;//r=lie c=hang
	while(r<=m){
		++cnt;
		if(a[cnt]==xr){
			cout<<r<<" "<<c<<endl;
			return 0;
		}
		if(r&1){
			if(c<n)c++;
			else r++;
		}else{
			if(c>1)c--;
			else r++;
		}
	}
	return 0;
}
