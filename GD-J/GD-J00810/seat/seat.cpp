#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[15][15];
int r[300];
/*
2 2
99 100 97 98

2 2
98 99 100 97
*/
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>r[i];
	}
	int R=r[1];
	sort(r+1,r+n*m+1,greater<int>());
	int k=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=r[k];
				k++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=r[k];
				k++;
			}
		}
	}
	int posi,posj;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==R){
				posi=i;
				posj=j;
				break;
			}
//			cout<<a[i][j]<<" ";
		}
//		cout<<endl;
	}
	cout<<posj<<" "<<posi;
	return 0;
}
