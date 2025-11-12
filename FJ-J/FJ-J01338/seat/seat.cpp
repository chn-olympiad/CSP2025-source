#include<bits/stdc++.h>
using namespace std;
bool cap(int a,int b){
	return a>b;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int x,y,sum=0,n[105],a[15][15],m=0;
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>n[i];
	}
	sum=n[1];
	sort(n+1,n+x*y+1,cap);
	if(sum==n[1]){
		cout<<1<<" "<<1;
	}
	for(int i=1;i<=x;i++){
		m=0;
		for(int j=1;j<=y;j++){
			if(i==1){
				a[i][j]=n[j];
			}
			if(i%2==0){
				a[i][j]=n[i*y-m];
				m++; 
			}
			
			if(sum==a[i][j]){
				cout<<i<<" "<<j;
			}
			
			
			
		}
	}
	return 0;
}
