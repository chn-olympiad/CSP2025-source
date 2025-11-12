#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[110];
int cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1, cmp);
	//for (int i=1;i<=n*m;i++){
	//	cout<<a[i]<<'\n';
	//}
	for (int i=0;i<n;i++){
		if(i==0||i%2==0){
			for(int j=1;j<=m;j++){
				if(x==a[i*m+j]) {
					cout<<i+1<<" "<<j;
					break;
				}
			}
		}
		else if(i%2==1){
			for (int j=1;j<=m;j++){
				if(x==a[i*m+j]) {
					cout<<i+1<<" "<<m-j+1;
					break;
				}
			}
		}
	}
	return 0;
}
