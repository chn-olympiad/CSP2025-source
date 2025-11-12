#include<bits/stdc++.h>
using namespace std;
int n,m,zmap[105][105],yc,xr=1,yr=1,w[10005],js=1;
bool cmp(int a,int b){
	if(a>b) return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>w[i];
	}
	yc=w[1];
	sort(w+1,w+1+m*n,cmp);
	while(1){
		zmap[xr][yr]=w[js];
		if(yc==zmap[xr][yr]){
			break;
		}
		if(xr==n&&yr%2!=0){
			yr++;
		}else if(xr<n&&yr%2!=0){
			xr++;
		}else if(xr>1&&yr%2==0){
			xr--;
		}else if(xr==1&&yr%2==0){
			yr++;
		}
		js++;
	}
	cout<<yr<<' '<<xr;
	return 0;
} 
