#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,a0,xa[12][12];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=m;j++){
			cin>>a[(i-1)*m+j];
		}
	}a0 = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j =1;j<=m;j++){
		if(j%2==0){
			for(int i = 1;i<=n;i++){
				xa[m-i+1][j] = a[(j-1)*n+i];
				if(a[(j-1)*n+i]==a0){
					cout<<j<<' '<<m-i+1;
					return 0;
				}
			}
		}else{
			for(int i = 1;i<=n;i++){
				xa[i][j] = a[(j-1)*n+i];
				if(a[(j-1)*n+i]==a0){
					cout<<j<<' '<<i;
					return 0;
				}
		}
	}
}
}
	
	
