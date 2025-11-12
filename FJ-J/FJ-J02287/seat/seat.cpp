#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[160],b[178],r,s=1,x,xr=1,yr=0,d=0,dd;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	dd=n;
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m; i>=1; i--){
		b[s]=a[i];
		if(a[i]==r){
			x=s;
		}
		s++;
	}
	for(int i=1; i<=n*m; i++){
		if(yr==dd){
			xr++;
			if(d==1){
				d=0;
			}
			else{
				d=1;
			}
			if(dd==n){
				dd=1;
			}
			else{
				dd=n;
			}
		}
		else if(d==0){
			yr++;
		}
		else if(d==1){
			yr--;
		}
		if(i==x){
			cout<<xr<<" "<<yr;
		}
		
	}
	
}
 

