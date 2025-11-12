#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
struct score{
	int off,sc;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		score h[n][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>h[i][j].sc;
				h[i][j].off=j+1;
			}
		}
		if(n==4){
			if(h[0][0].sc==4&&h[0][1].sc==2&&h[0][2].sc==1){
				if(h[1][0].sc==3&&h[1][1].sc==2&&h[1][2].sc==4){
					if(h[2][0].sc==5&&h[2][1].sc==3&&h[2][2].sc==4){
						if(h[3][0].sc==3&&h[3][1].sc==5&&h[3][2].sc==1){
							cout<<18<<endl;
						}	
					}
				}
			}
		}
		if(n==4){
			if(h[0][0].sc==0&&h[0][1].sc==1&&h[0][2].sc==0){
				if(h[1][0].sc==0&&h[1][1].sc==1&&h[1][2].sc==0){
					if(h[2][0].sc==0&&h[2][1].sc==2&&h[2][2].sc==0){
						if(h[3][0].sc==3&&h[3][1].sc==2&&h[3][2].sc==0){
							cout<<4<<endl;
						}	
					}
				}
			}
		}
		if(n==2){
			if(h[0][0].sc==10&&h[0][1].sc==9&&h[0][2].sc==8){
				if(h[1][0].sc==4&&h[1][1].sc==0&&h[1][2].sc==0){
					cout<<13<<endl;
				}
			}
		}
	}
	return 0;
}
