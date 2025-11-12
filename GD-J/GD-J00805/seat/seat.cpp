#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[20][20],js;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[++js];
			}
		}
		else{
			for(int j=1;j<=m;j++){
				b[i][j]=a[++js];
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans==b[i][j]) cout<<i<<" "<<j;
		}
	}
	return 0;
}
