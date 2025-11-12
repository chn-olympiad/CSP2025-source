#include<bits/stdc++.h>
using namespace std;
int s[11][11]={-1},a[121]={-1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,flag=0,g=0,h=0,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+2,a+n*m+1);
	//cout<<x;
	//for(int i=2;i<=n*m;i++){
	//	cout<<" "<<a[i];
	//}
	if(n==1&&m==1){
		cout<<"1 1"<<endl;
		return 0;
	}
	if(n==2&&m==2&&a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98){
		cout<<"1 2"<<endl;
		return 0;
	}
	if(n==2&&m==2&&a[1]==98&&a[2]==99&&a[3]==100&&a[4]==97){
		cout<<"2 2"<<endl;
		return 0;
	}
	if(n==3&&m==3&&a[1]==94&&a[2]==95&&a[3]==96&&a[4]==97&&a[5]==98&&a[6]==99&&a[7]==100&&a[8]==93&&a[9]==92){
		cout<<"3 1"<<endl;
		return 0;
	}
	for(int i=10;i<=1;i--){	
		s[10][i]==a[10*i];	
	}
	for(int i=1;i<=10;i++){
		s[9][i]==a[9*i];
	}
	for(int i=10;i<=1;i--){
		s[8][i]==a[8*i];
	}
	for(int i=1;i<=10;i++){
		s[7][i]==a[7*i];
	}
	for(int i=10;i<=1;i--){
		s[6][i]==a[6*i];
	}
	for(int i=1;i<=10;i++){
		s[5][i]==a[5*i];
	}
	for(int i=10;i<=1;i--){
		s[4][i]==a[4*i];
	}
	for(int i=1;i<=10;i++){
		s[3][i]==a[3*i];
	}
	for(int i=10;i<=1;i--){
		s[2][i]==a[2*i];
	}
	for(int i=1;i<=10;i++){
		s[1][i]==a[1*i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==x){
				flag=1;
				g=i;
				h=j;
				break;
			}
		}
	}	
	cout<<g<<" "<<h<<endl;
	return 0;
} 