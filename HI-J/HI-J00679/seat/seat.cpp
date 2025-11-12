#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005][1005];
int b[1005];
int c,d=1,js;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[js+1];
			js++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==c){
				cout<<i<<" ";
				if(i%2==0){
					cout<<n-j+1;
				}else{
					cout<<j;
				}
			}
		}
	}
	return 0;
}
