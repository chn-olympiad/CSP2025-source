#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[15][15];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int d=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[x++];
			}
		}
		else if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[x++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==d){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}