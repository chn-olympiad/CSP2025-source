#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,nx,ny;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			cnt++;
		}
	}
	nx=1;
	ny=1;
	for(int i=1;i<=n*m;i++){
		if(i==cnt){
			cout<<nx<<' '<<ny;
			return 0;
		} 
		if(ny==n&&(nx&1)){
			nx++;
			continue;
		}
		if(ny==1&&(nx%2==0)){
			nx++;
			continue;
		}
		if(nx&1){
			ny++;
		}
		else{
			ny--;
		}
	}
}
