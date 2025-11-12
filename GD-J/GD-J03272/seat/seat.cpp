#include<bits/stdc++.h>
using namespace std;

int kaochang[50][50];
int ren[10000],ks,maxa,n,m;
int ans,h=0,xr=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin >> n >> m;
	ks = n*m;
	for(int i=1;i<=ks;i++){
		cin >> ren[i];
	}
	for(int i=1;i<=m;i++){
		if(xr == 1){
			break;
		}
		else if(h==0){
			for(int j=1;j<=n;j++){
			maxa = 0;
			ans = 0;
			for(int z=1;z<=ks;z++){
				if(maxa < ren[z]){
					maxa = ren[z];
					ans = z;
					}
				}
			kaochang[i][j] = maxa;
			if(kaochang[i][j] == ren[1]){
				cout << i << " " << j;
				xr=1;
				break;
				}
			ren[ans] = 0;
			}
			h++;
		}
		else if(h==1){
			for(int j=n;j>=1;j--){
			maxa = 0;
			ans = 0;
			for(int z=1;z<=ks;z++){
				if(maxa < ren[z]){
					maxa = ren[z];
					ans = z;
					}
				}
			kaochang[i][j] = maxa;
			if(kaochang[i][j] == ren[1]){
				cout << i << " " << j;
				xr=1;
				break;
				}
			ren[ans] = 0;
			}
			h--;
		}
	}
	return 0;
}
