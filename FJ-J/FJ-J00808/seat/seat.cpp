#include<bits/stdc++.h>
using namespace std;
int arr[100],brr[100][100];
int n,m,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&arr[i]);
		r=arr[1];
	}
	sort(arr+1,arr+n*m+1,cmp);	
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1){
		for(int i=1;i<=m;i++){
			if(arr[i]==r){
				cout<<1<<" "<<i;
				return 0;
			}
		}	
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(arr[i]==r){
				cout<<i<<" "<<1;
				return 0;
			}
		}	
	}
	if(n==2&&m==2){
		brr[1][1]=arr[1];brr[n][1]=arr[2];
		brr[n][2]=arr[3];brr[1][2]=arr[n*m];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==3){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[n*m];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==4){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[6];
		brr[2][4]=arr[7];brr[1][4]=arr[8];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==5){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[6];
		brr[2][4]=arr[7];brr[1][4]=arr[8];
		brr[1][5]=arr[9];brr[2][5]=arr[10]; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==6){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[6];
		brr[2][4]=arr[7];brr[1][4]=arr[8];
		brr[1][5]=arr[9];brr[2][5]=arr[10]; 
		brr[2][6]=arr[11];brr[1][6]=arr[12];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==7){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[6];
		brr[2][4]=arr[7];brr[1][4]=arr[8];
		brr[1][5]=arr[9];brr[2][5]=arr[10]; 
		brr[2][6]=arr[11];brr[1][6]=arr[12];
		brr[1][7]=arr[13];brr[2][7]=arr[14];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==8){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[6];
		brr[2][4]=arr[7];brr[1][4]=arr[8];
		brr[1][5]=arr[9];brr[2][5]=arr[10]; 
		brr[2][6]=arr[11];brr[1][6]=arr[12];
		brr[1][7]=arr[13];brr[2][7]=arr[14];
		brr[2][8]=arr[15];brr[1][8]=arr[16];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==9){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[6];
		brr[2][4]=arr[7];brr[1][4]=arr[8];
		brr[1][5]=arr[9];brr[2][5]=arr[10]; 
		brr[2][6]=arr[11];brr[1][6]=arr[12];
		brr[1][7]=arr[13];brr[2][7]=arr[14];
		brr[2][8]=arr[15];brr[1][8]=arr[16];
		brr[1][9]=arr[17];brr[2][9]=arr[18];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==2&&m==10){
		brr[1][1]=arr[1];brr[2][1]=arr[2];
		brr[2][2]=arr[3];brr[1][2]=arr[4];
		brr[1][3]=arr[5];brr[2][3]=arr[6];
		brr[2][4]=arr[7];brr[1][4]=arr[8];
		brr[1][5]=arr[9];brr[2][5]=arr[10]; 
		brr[2][6]=arr[11];brr[1][6]=arr[12];
		brr[1][7]=arr[13];brr[2][7]=arr[14];
		brr[2][8]=arr[15];brr[1][8]=arr[16];
		brr[1][9]=arr[17];brr[2][9]=arr[18];
		brr[2][10]=arr[19];brr[1][10]=arr[20];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==2){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==3){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==4){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		brr[3][4]=arr[10];brr[2][4]=arr[11];brr[1][4]=arr[12];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==5){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		brr[3][4]=arr[10];brr[2][4]=arr[11];brr[1][4]=arr[12];
		brr[1][5]=arr[13];brr[2][5]=arr[14];brr[3][5]=arr[15];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==6){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		brr[3][4]=arr[10];brr[2][4]=arr[11];brr[1][4]=arr[12];
		brr[1][5]=arr[13];brr[2][5]=arr[14];brr[3][5]=arr[15];
		brr[3][6]=arr[16];brr[2][6]=arr[17];brr[1][6]=arr[18];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==7){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		brr[3][4]=arr[10];brr[2][4]=arr[11];brr[1][4]=arr[12];
		brr[1][5]=arr[13];brr[2][5]=arr[14];brr[3][5]=arr[15];
		brr[3][6]=arr[16];brr[2][6]=arr[17];brr[1][6]=arr[18];
		brr[1][7]=arr[19];brr[2][7]=arr[20];brr[3][7]=arr[21];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==8){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		brr[3][4]=arr[10];brr[2][4]=arr[11];brr[1][4]=arr[12];
		brr[1][5]=arr[13];brr[2][5]=arr[14];brr[3][5]=arr[15];
		brr[3][6]=arr[16];brr[2][6]=arr[17];brr[1][6]=arr[18];
		brr[1][7]=arr[19];brr[2][7]=arr[20];brr[3][7]=arr[21];
		brr[3][8]=arr[22];brr[2][8]=arr[23];brr[1][8]=arr[24];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==9){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		brr[3][4]=arr[10];brr[2][4]=arr[11];brr[1][4]=arr[12];
		brr[1][5]=arr[13];brr[2][5]=arr[14];brr[3][5]=arr[15];
		brr[3][6]=arr[16];brr[2][6]=arr[17];brr[1][6]=arr[18];
		brr[1][7]=arr[19];brr[2][7]=arr[20];brr[3][7]=arr[21];
		brr[3][8]=arr[22];brr[2][8]=arr[23];brr[1][8]=arr[24];
		brr[1][9]=arr[25];brr[2][9]=arr[26];brr[3][9]=arr[27];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	if(n==3&&m==10){
		brr[1][1]=arr[1];brr[2][1]=arr[2];brr[3][1]=arr[3];
		brr[3][2]=arr[4];brr[2][2]=arr[5];brr[1][2]=arr[6];
		brr[1][3]=arr[7];brr[2][3]=arr[8];brr[3][3]=arr[9];
		brr[3][4]=arr[10];brr[2][4]=arr[11];brr[1][4]=arr[12];
		brr[1][5]=arr[13];brr[2][5]=arr[14];brr[3][5]=arr[15];
		brr[3][6]=arr[16];brr[2][6]=arr[17];brr[1][6]=arr[18];
		brr[1][7]=arr[19];brr[2][7]=arr[20];brr[3][7]=arr[21];
		brr[3][8]=arr[22];brr[2][8]=arr[23];brr[1][8]=arr[24];
		brr[1][9]=arr[25];brr[2][9]=arr[26];brr[3][9]=arr[27];
		brr[3][10]=arr[28];brr[2][10]=arr[29];brr[1][10]=arr[30];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][j]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
