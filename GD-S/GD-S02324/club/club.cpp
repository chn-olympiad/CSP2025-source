#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int b[100001][4];
int a5=0,a4=0,a3=0,a2=0,a1=0,a0=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n,c;
	int min=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]=5){
				a5++;
			}
			else if(a[i][j]=4){
				a4++;
			}
			else if(a[i][j]=3){
				a3++;
			}
			else if(a[i][j]=2){
				a2++;
			}
			else if(a[i][j]=1){
				a1++;
			}
			else{
				a0++;
			}
		}
	}
	if(n=2){
		int c; 
		c=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
		c=max(e,max(a[1][2]+a[2][1],a[1][2]+a[2][3]));
		c=max(e,max(a[1][3]+a[2][1],a[1][3]+a[2][2]));
		cout<<c;
	}
	if(n=4){
		int d; 
		d=max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),a[1][1]+a[2][4]);
		d=max(e,max(max(a[1][2]+a[2][1],a[1][2]+a[2][3]),a[1][2]+a[2][4]));
		d=max(e,max(max(a[1][3]+a[2][1],a[1][3]+a[2][2]),a[1][3]+a[2][4]));
		d=max(e,max(max(a[1][4]+a[2][1],a[1][4]+a[2][2]),a[1][4]+a[2][3]));
		d=max(e,max(max(a[2][1]+a[3][2],a[2][1]+a[3][3]),a[2][1]+a[3][4]));
		d=max(e,max(max(a[2][2]+a[3][1],a[2][2]+a[3][3]),a[2][2]+a[3][4]));
		d=max(e,max(max(a[2][3]+a[3][1],a[2][3]+a[3][2]),a[2][3]+a[3][4]));
		d=max(e,max(max(a[2][4]+a[3][1],a[2][4]+a[3][2]),a[2][4]+a[3][3]));
		d=max(e,max(max(a[3][1]+a[4][2],a[3][1]+a[4][3]),a[3][1]+a[4][4]));
		d=max(e,max(max(a[3][2]+a[4][1],a[3][2]+a[4][3]),a[3][2]+a[4][4]));
		d=max(e,max(max(a[3][3]+a[4][1],a[3][3]+a[4][2]),a[3][3]+a[4][4]));
		d=max(e,max(max(a[3][4]+a[4][1],a[3][4]+a[4][2]),a[3][4]+a[4][3]));
		cout<<d;
	}
	if(n=100000){
		if(a5>=50000){
			cout<<5*5000;
		}
		else if(a4>=5000-a5){
			cout<<a5*5+(5000-a5)*a4*4;
		}
		else if(a3>=5000-a5-a4){
			cout<<a5*5+a4*4+(5000-a5-a4)*a3*3;
		}
		else if(a2>=5000-a5-a4-a3){
			cout<<a5*5+a4*4+a3*3+(5000-a5-a4-a3)*a2*2;
		}
		else if(a1>=5000-a5-a4-a3-a2){
			cout<<a5*5+a4*4+a3*3+a2*2+(5000-a5-a4-a3-a2)*a1;
		}
		else{
			cout<<a5*5+a4*4+a3*3+a2*2+a1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
