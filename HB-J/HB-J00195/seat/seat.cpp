#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[105],c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=0,r;
	cin>>n>>m;
	cin>>b[1];
	r=b[1];
	//cout<<"r="<<r<<endl;
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		c[i]=b[n*m-i+1];
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				t++;
				//cout<<"t="<<t<<endl;
				a[i][j]=c[t];
				//cout<<"i j="<<i<<" "<<j<<endl;
				//cout<<"a[i][j]="<<a[i][j]<<endl;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				t++;
				//cout<<"t="<<t<<endl;
				a[i][j]=c[t];
				//cout<<"i j="<<i<<" "<<j<<endl;
				//cout<<"a[i][j]="<<a[i][j]<<endl;
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			//cout<<"a="<<a[n][m]<<endl;
			if(a[i][j]==r){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
