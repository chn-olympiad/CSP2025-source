#include<bits/stdc++.h>
using namespace std;
int m,n,r,cnt=0;
int a[1100];
int f[100][100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	/*for(int i=1;i<=n*m;i++){
		cout<<a[i]<<' ';
	}*/
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				f[i][j]=a[++cnt];
			}
		}
		else{
			for(int j=m;j>=1;j--){
				f[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==r){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
