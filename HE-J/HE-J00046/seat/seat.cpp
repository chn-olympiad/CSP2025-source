#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,rs;
int sum[50][50];
int b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}rs=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		b[n*m-i+1]=a[i];
	} 
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				sum[j][i]=b[++cnt];
			} 
		}else{
			for(int j=n;j>=1;j--){
				sum[j][i]=b[++cnt];
			} 
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<sum[i][j]<<" ";;
		}
		cout<<endl;
	}*/
	//cout<<rs;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sum[i][j]==rs){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0; 
} 
