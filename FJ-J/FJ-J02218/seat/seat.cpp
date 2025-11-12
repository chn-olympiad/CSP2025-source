#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[1000]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==tmp){
					cout<<i<<' '<<j;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[(i-1)*n+(n-j+1)]==tmp){
					cout<<i<<' '<<j;
				}
			}
		}
	}
	return 0;
}


