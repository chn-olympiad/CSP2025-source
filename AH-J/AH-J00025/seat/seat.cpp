#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,s=1;
	while(s<=n*m){
		for(i=1;i<=n;i++){
			b[i][j]=a[s];
			s++;
		}
		j++;
		for(i=n;i>=1;i--) {
			b[i][j]=a[s];
			s++;
		}
		j++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
