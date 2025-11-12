#include<bits/stdc++.h>
using namespace std;
int n,m;
struct data1{
	int x,i;
}a[15*15];
bool cmp(data1 x,data1 y){
	return x.x>y.x;
}
int xb=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].i=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				xb++;
				if(a[xb].i==1){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				xb++;
				if(a[xb].i==1){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
