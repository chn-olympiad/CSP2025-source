#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int m,n;
	cin>>m>>n;
	int per=m*n;
	int a[per];
	int xr;
	for (int i=0 ;i<per; i++){
		cin>>a[i];
	}
	xr=a[0];
	sort(a,a+per);
	int h=1,l=1;
	int zx=1;
	for (int i=per-1 ;i>=0; i--){
		

		
		
		if(xr==a[i]){
			cout<<l<<' '<<h;
			break;
		}
		if (zx){
			h++;	
		}else{
			h--;
		}
		
		if(h>m){
			h=m;
			zx=0;
			l++;
		}
		if (h==0){
			h=1;
			zx=1;
			l++;
		}
		
	}
	
	
	return 0;
}
