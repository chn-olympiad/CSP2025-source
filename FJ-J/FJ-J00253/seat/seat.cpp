#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
bool dx(int x,int y){
	return x>y;
}
int m,n,chengji[110],chengji_r,a,a_x,a_y;
int zb[105][105],shu=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>chengji[i];
	}
	chengji_r=chengji[1];
	sort(chengji+1,chengji+n*m+1,dx);
	for(int i=1;i<=n/2+1;i++){
		for(int j=1;j<=m;j++){
			zb[i*2-1][j]=chengji[shu];
			shu++;
		}
		for(int j=n;j>=1;j--){
			zb[i*2][j]=chengji[shu];
			shu++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(chengji_r==zb[i][j]){
				a_x=i;
				a_y=j;
			}
		}
	}
	cout<<a_x<<" "<<a_y;
	return 0;
	
}
