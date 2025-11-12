#include<bits/stdc++.h>
using namespace std;
int n,m;
int cj[200],xr,zw;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	xr=cj[1];
	sort(cj+1,cj+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(cj[i]==xr){
			zw=i;
			break;	
		}
	}
	zw=n*m-zw+1;
	int h=ceil(1.0*zw/n),w=zw%n;
	if(w==0)w=n;
	if(h%2==0)w=n-w+1;
	cout<<h<<" "<<w;
	return 0;
}