#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==a1){
			a1=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1)
		for(int j=1;j<=n;j++){
			if((i-1)*n+j==a1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		else
		for(int j=1;j<=n;j++){
			if((i-1)*n-j+n==a1){
				cout<<i<<" "<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}
