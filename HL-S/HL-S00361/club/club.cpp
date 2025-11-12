#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++){
		int c;
		cin >>c;
		for(int j=0;j<c;j++){
			int  cx[6][100010],ac=0,bc=0,cc=0,r=0;
			for(int z=0;z<100000;z++){
				cin >> cx[0][z];
				cin >> cx[1][z];
				cin >> cx[2][z];
				if(cx[0][z]>cx[1][z]&&cx[1][z]>cx[2][z]){
					cx[3][z]=cx[0][z]-cx[1][z];
					cx[4][z]=1;
					cx[5][z]=2;
					ac+=1;
				}
				if(cx[0][z]>cx[2][z]&&cx[2][z]>cx[1][z]){
					cx[3][z]=cx[0][z]-cx[2][z];
					cx[4][z]=1;
					cx[5][z]=3;
					ac+=1;
				}
				if(cx[1][z]>cx[0][z]&&cx[0][z]>cx[2][z]){
					cx[3][z]=cx[1][z]-cx[0][z];
					cx[4][z]=2;
					cx[5][z]=1;
					bc+=1;
				}
				if(cx[1][z]>cx[2][z]&&cx[2][z]>cx[0][z]){
					cx[3][z]=cx[1][z]-cx[2][z];
					cx[4][z]=2;
					cx[5][z]=3;
					bc+=1;
				}
				if(cx[2][z]>cx[0][z]&&cx[0][z]>cx[1][z]){
					cx[3][z]=cx[2][z]-cx[0][z];
					cx[4][z]=3;
					cx[5][z]=1;
					cc+=1;
				}
				if(cx[2][z]>cx[1][z]&&cx[1][z]>cx[0][z]){
					cx[3][z]=cx[2][z]-cx[1][z];
					cx[4][z]=3;
					cx[5][z]=2;
					cc+=1;
				}
			}
			if(ac>bc&& ac>cc &&ac>c/2){
				int countt=ac-c/2,cha=0;
				for(int z=0;z<100000;z++){
					if(cx[4][z]==1){
						r+=cx[0][z];
					}
					if(cx[4][z]==2){
						r+=cx[1][z];
					}
					if(cx[4][z]==3){
						r+=cx[2][z];
					}
				}
				for(int z=0;z<100000;z++){
					for(int t=1;t<1000;t++){
						if(cx[3][z]==t&&cx[4][z]==1){
							countt-=1;
							cha+=t;
							if(countt==0){
								break;
							}
						}
					}
				}
				r-=cha;
			}
			else if(ac>bc&& ac>cc){
				int countt=ac-c/2,cha=0;
				for(int z=0;z<100000;z++){
					if(cx[4][z]==1){
						r+=cx[0][z];
					}
					if(cx[4][z]==2){
						r+=cx[1][z];
					}
					if(cx[4][z]==3){
						r+=cx[2][z];
					}
				}
			}
			if(bc>ac&& bc>cc &&bc>c/2){
				int countt=bc-c/2,cha=0;
				for(int z=0;z<100000;z++){
					if(cx[4][z]==1){
						r+=cx[0][z];
					}
					if(cx[4][z]==2){
						r+=cx[1][z];
					}
					if(cx[4][z]==3){
						r+=cx[2][z];
					}
				}
				for(int z=0;z<100000;z++){
					for(int t=1;t<1000;t++){
						if(cx[3][z]==t&&cx[4][z]==2){
							countt-=1;
							cha+=t;
							if(countt==0){
							break;
							}
						}
					}
				}
				r-=cha;
			}
			else if(bc>ac&& bc>cc){
				int countt=bc-c/2,cha=0;
				for(int z=0;z<100000;z++){
					if(cx[4][z]==1){
						r+=cx[0][z];
					}
					if(cx[4][z]==2){
						r+=cx[1][z];
					}
					if(cx[4][z]==3){
						r+=cx[2][z];
					}
				}
			}
			if(cc>bc&& cc>ac &&cc>c/2){
				int countt=cc-c/2,cha=0;
				for(int z=0;z<100000;z++){
					if(cx[4][z]==1){
						r+=cx[0][z];
					}
					if(cx[4][z]==2){
						r+=cx[1][z];
					}
					if(cx[4][z]==3){
						r+=cx[2][z];
					}
				}
				for(int z=0;z<100000;z++){
					for(int t=1;t<1000;t++){
						if(cx[3][z]==t&&cx[4][z]==3){
							countt-=1;
							cha+=t;
							if(countt==0){
							break;
							}
						}
					}
				}
				r-=cha;
			}
			else if(cc>bc&& cc>ac){
				int countt=cc-c/2,cha=0;
				for(int z=0;z<100000;z++){
					if(cx[4][z]==1){
						r+=cx[0][z];
					}
					if(cx[4][z]==2){
						r+=cx[1][z];
					}
					if(cx[4][z]==3){
						r+=cx[2][z];
					}
				}
			}
			cout << r;
		}
	}
	return 0;
}