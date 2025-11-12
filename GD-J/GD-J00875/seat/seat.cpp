#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1888];
int s[18][18];
int r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(i%2==1) s[j][i]=a[i*n-n+j];
			else s[n-j+1][i]=a[i*n-n+j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==r){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}
