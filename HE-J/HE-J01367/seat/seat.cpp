#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
bool com(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+10];
	a[0]=0;
	int x[n+1][m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,com);
	int o=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				x[j][i]=a[o];
				o++;
			}
		}else{
			for(int j=n;j>=1;j--){
				x[j][i]=a[o];
				o++;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]==sum){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
} 
