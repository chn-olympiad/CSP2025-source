#include<iostream>
using namespace std;
int m,n,seat[20][20],a[200],a1,num=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-i;j++){
			if(a[j]<a[j+1]){
				a[j+1]=a[j+1]-a[j];
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
			}
		}
	}
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				//seat[j][i]=a[++num];
				num++;
				if(a1==a[num])cout<<i<<' '<<j<<endl;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				//seat[j][i]=a[++num];
				num++;
				if(a1==a[num])cout<<i<<' '<<j<<endl;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<seat[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
}
