#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[n*m+1],d[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int r=c[1],xr;
	sort(c+1,c+n*m+1);
	for(int i=1;i<=n*m;i++){
		d[i]=c[n*m-i+1];
	}
	for(int i=1;i<=n*m;i++){
		if(d[i]==r){
			xr=i;
		}
	}
	int h,l;
	h=xr%n;
	if(h==0){
		l=xr/n;
		h=n;
	}
	else l=xr/n+1;
	if(l%2==0)h=n-h+1;
	cout<<l<<" "<<h;
	return 0;       
}