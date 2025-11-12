#include<bits/stdc++.h>
using namespace std;
int n,m,kf,a[1005],tot;
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) kf=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				tot++;
				if(a[tot]==kf){
					cout<<j<<" "<<i;
					break;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				tot++;
				if(a[tot]==kf){
					cout<<j<<" "<<i;
					break;
				}
			}
		}
	}
	return 0;
}
