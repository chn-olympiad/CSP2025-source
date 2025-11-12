#include<bits/stdc++.h>
using namespace std;
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z,x,j,d=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		z=b[1];
	}
	x=n%2;
	if(x==1){
		j=m+1;
	}else{
		j=1;
	}
	sort(b+1,b+1+n*m);
	for(int i=n;i>=1;i--){
		if(x==1){
			for(;j>=1;--j){
				if(b[d]==z){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
			x=0;
		}else{
			for(;j<=m;++j){
				if(b[d]==z){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
			x++;
		}
	}
	return 0;
} 