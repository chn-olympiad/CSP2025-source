#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[120];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i+=0){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*m+j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			if(a[(i-1)*m+(n-j+1)]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
	}
	return 0;
}
