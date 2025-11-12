#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int xr;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1);
	int i1=1,j1=1,k=0,x=n*m;
	while(true){
		if(a[x]==xr){
			cout<<j1<<" "<<i1;
			break;
		}
		if(i1==n&&k==0){
			k=1;
			j1++;
			x--;
			continue;
		}
		if(i1==1&&k==1){
			j1++;
			k=0;
			x--;
			continue;
		}
		if(k==0) i1++;
		if(k==1) i1--;
		x--;
	}
	return 0;
}