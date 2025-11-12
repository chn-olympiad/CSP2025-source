#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,y,R;
	cin>>n>>m;
	y=n*m;
	int a[y];
	for(long long i=1;i<=y;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a,a+y);
	int z[m][n];
	for(long long p=1;p<=y;p++){
	for(long long i=1;i<=m;i++){
		if(i%2==1){
			for(long long j=1;j<=n;j++){
				z[i][j]=a[p];	
			}
		}
		else if(i%2==0){
			for(long long j=n;j>=1;j--){
				z[i][j]=a[p];	
			}
		}
	}
	}
	bool flag=true;
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;i++){
			if(z[i][j]==R){
				cout<<i-1<<" "<<j;
				flag=false;
				break;
			}
	}
	if(flag==false){
		break;
	}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
