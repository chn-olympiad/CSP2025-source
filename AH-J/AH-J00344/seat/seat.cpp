#include<bits/stdc++.h>
using namespace std;
int a[10001],b[101][101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
	int n,m,ans;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)  ans=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int s=0,i=1,j=1;
	while(s<=n*m){
		if(j%2==1){
			while(i<=n){b[i][j]=a[++s];i++;}
			i=n;
			j++;
		}else if(j%2==0){
			while(i>=1){b[i][j]=a[++s];i--;}
			i=1;
			j++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
