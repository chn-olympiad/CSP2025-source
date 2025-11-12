#include<bits/stdc++.h>
//#define int longlong
using namespace std;
long long int a[10000][10000],n,m,o,b=100,xx=1,yy=1,u=0,v=0;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	o = a[1][1];
	for(int k=1;k<=100;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j] == b){
					int xy=a[xx][yy];
					a[xx][yy] = a[i][j];
					a[i][j] = xy;
					b--;
					v=1;
					if(xx==n&&u==0){
						u=1;
						yy++;
					}else if(xx==1&&u==1){
						u=0;
						yy++;
					}else if(u==0){
						xx++;
					}else if(u==1){
						xx--;
					}
				}
			}
		}
		if(v==0){
			b--;
		}else{
			v=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<' ';
			if(a[i][j]==o){
				cout<<j<<' '<<i;
				return 0;
			}
		}
//		cout<<endl;
	}
}

