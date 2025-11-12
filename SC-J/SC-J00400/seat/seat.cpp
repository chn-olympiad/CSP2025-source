#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int a[150];
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[k];
				k++;
			}
		}else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[k];
				k++;
			}
		}
	}bool flag=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==R){cout<<j<<" "<<i;return 0;}
		}
	}
	return 0;
}