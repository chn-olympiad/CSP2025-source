//seat.cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[11][11],k,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=(n*m);i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+(n*m)+1);
//	for(int i=1;i<=(n*m);i++) cout<<a[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				b[j][i]=a[n*m-k];
			}
			else{
				b[n-j+1][i]=a[n*m-k];
			}
			k++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
//			cout<<b[i][j]<<' ';
			if(b[i][j]==x){
				printf("%d %d",j,i);
				return 0;	
			} 
		}
//		cout<<endl;
	}
	return 0;
}
/*
2 2
99 100 97 98
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/
