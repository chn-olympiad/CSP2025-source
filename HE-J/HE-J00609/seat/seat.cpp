#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[350],st[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r_sc=a[1],p=1;
	sort(a+1,a+n*m+1,cmp);
	for(j=1;j<=m;j++){
		if(j%2==1){
			for(i=1;i<=n;i++){
				st[i][j]=a[p];
				p++;
			}
		}else{
			for(i=n;i>=1;i--){
				st[i][j]=a[p];
				p++;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(st[i][j]==r_sc){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
