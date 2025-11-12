#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],b[100010],mi[100010];
int all(int x,int c[]){
	int y=20000;
	for(int i=1;i<=x;i++){
		y=min(y,c[i]);
	}
	for(int i=1;i<=x;i++){
		if(y==c[i]){
			c[i]=20000;
		}
		break;
	}
	return y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		cin>>n;
		int ma,num1,num2,num3;
		ma=0;
		num1=0;
		num2=0;
		num3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				ma=max(ma,a[i][j]);
			}
			mi[i]=20000;
			if(ma==a[i][1]&&ma!=a[i][2]&&ma!=a[i][3]){
				num1++;
				mi[i]=min(mi[i],(a[i][1]-(max(a[i][2],a[i][3]))));
			}
			else if(ma!=a[i][1]&&ma==a[i][2]&&ma!=a[i][3]){
				num2++;
				mi[i]=min(mi[i],(a[i][2]-(max(a[i][1],a[i][3]))));
			}
			else if(ma!=a[i][1]&&ma!=a[i][2]&&ma==a[i][3]){
				num3++;
				mi[i]=min(mi[i],(a[i][3]-(max(a[i][1],a[i][2]))));
			}
			else if(ma==a[i][1]&&ma==a[i][2]&&ma!=a[i][3]){
				if(min(num1,num2)==num1) num1++;
				else num2++;
			}
			else if(ma==a[i][1]&&ma!=a[i][2]&&ma==a[i][3]){
				if(min(num1,num3)==num1) num1++;
				else num3++;
			}
			else if(ma!=a[i][1]&&ma==a[i][2]&&ma==a[i][3]){
				if(min(num2,num3)==num2) num2++;
				else num3++;
			}
			else if(ma==a[i][1]&&ma==a[i][2]&&ma==a[i][3]){
				if(min(num1,num2)==num1){
					if(min(num1,num3)==num1) num1++;
					else num3++;
				}
				else{
					if(min(num2,num3)==num2) num2++;
					else num3++;
				}
			}
			b[i]=ma;
			ma=0;
		}
		int he=0,da=0;
		if(num1+num2<num3){
			int cha=(num3-max(num1,num2))/2;
			for(int j=1;j<=cha;j++){
				he=he+all(n,mi);
			}
		}
		else if(num1+num3<num2){
			int cha=(num2-max(num1,num3))/2;
			for(int j=1;j<=cha;j++){
				he=he+all(n,mi);
			}
		}
		else if(num2+num3<num1){
			int cha=(num1-max(num2,num3))/2;
			for(int j=1;j<=cha;j++){
				he=he+all(n,mi);
			}
		}
		for(int i=1;i<=n;i++){
			da=da+b[i];
		}
		cout<<da-he;
	}
	return 0;
}
