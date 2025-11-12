#include <bits/stdc++.h> 
using namespace std;


bool cmp(int a,int b){
	return a>b;
}
int seating[15][15],sc[255],n,m,sst,xrx,xry,xrs;//sst=学生，xrx=小RX坐标，xry=小RY坐标，xrs=小R的分数 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> sc[i];
	}xrs = sc[1];
	bool isdown = 0;
	sort(sc+1,sc+n*m+1,cmp);
		for(int i = 1;i<=m;i++){//shuzhededitu;
			isdown = !isdown;
			if(isdown){
				for(int j = 1;j<=n;j++){
					sst++;
					seating[j][i]=sc[sst];
					if(sc[sst]==xrs) {
						xry = i;xrx = j;break;
					}
				}
			}
			else{
				for(int j = n;j>=1;j--){
					sst++;
					seating[j][i]=sc[sst];
					if(sc[sst]==xrs) {
						xry = i;xrx = j;break;
					}
				}
			}
		}
	/*for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			printf("%-5d",seating[i][j]);
		}
		cout << endl;
	}
	cout << "\n";*/
	cout << xry << " " << xrx;
	return 0;
}
