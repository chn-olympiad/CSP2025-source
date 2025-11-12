#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,r,c,a1,cnt=0;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++){
		if(i%2==1){
			for(j=1;j<=n;j++){
				cnt++;
				b[j][i]=a[cnt];
			}
		}else{
			for(j=n;j>=1;j--){
				cnt++;
				b[j][i]=a[cnt];
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(b[i][j]==a1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
