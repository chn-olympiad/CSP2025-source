#include<iostream>
using namespace std;

int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int seat[n+10][m+10];
	int a[n*m+10]={-1};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int R=a[1];
	
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(a[j]<a[j+1]){
				int q1=a[j];
				a[j]=a[j+1];
				a[j+1]=q1;
			}
		}
	}
	
	int num=1;
	for(int i=1;i<=m;i++){
		if(num>n*m){
			break;
		}
		else if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[n][m]=a[num];
				num++;
			}
		}else if(i%2==0){
			for(int j=n;j>0;j--){
				seat[n][m]=a[num];
				num++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==R){
				cout<<j<<" "<<i<<endl;
				break;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
