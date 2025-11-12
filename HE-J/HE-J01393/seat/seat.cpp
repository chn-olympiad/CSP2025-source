#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a1,a[15][15]={0},b[105]={0};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int i,j,k;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	b[0]=a1;
	for(i=1;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b,b+n*m,cmp);
	k=0;
	for(i=1;i<=n;i++){
		if(i%2!=0){
			for(j=1;j<=m;j++){
				a[i][j]=b[k];
				k++;
			}
		}
		else{
			for(j=m;j>=1;j--){
				a[i][j]=b[k];
				k++;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]==a1){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
