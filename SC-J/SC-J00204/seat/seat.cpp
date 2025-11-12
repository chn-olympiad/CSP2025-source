#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],ming;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=0;i<num;i++)cin>>a[i];
	ming=a[0];
	sort(a,a+num);
	reverse(a,a+num);
	int hed=0;
	int result[15][15];
	if(m==1){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][4]=a[hed++];
		}
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][4]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][5]=a[hed++];
		}
	}
	else if(m==6){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][4]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][5]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][6]=a[hed++];
		}
	}
	else if(m==7){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][4]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][5]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][6]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][7]=a[hed++];
		}
	}
	else if(m==8){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][4]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][5]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][6]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][7]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][8]=a[hed++];
		}
	}
	else if(m==9){
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][4]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][5]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][6]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][7]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][8]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][9]=a[hed++];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			result[i][1]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][2]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][3]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][4]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][5]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][6]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][7]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][8]=a[hed++];
		}
		for(int i=1;i<=n;i++){
			result[i][9]=a[hed++];
		}
		for(int i=n;i>0;i--){
			result[i][10]=a[hed++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(result[i][j]==ming){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}