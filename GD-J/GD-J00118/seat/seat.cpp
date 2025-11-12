#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101],b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
			cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+len);
	int i=1,j=1;
	b[1][1]=a[len];
	while(len){
		if(j%2==1){
			if(i!=n){
				b[i+1][j]=a[--len];
				i++;
			}
			else{
				b[i][j+1]=a[--len];
				j++;
			}
		}
		else{
			if(i!=1){
				b[i-1][j]=a[--len];
				i--;
			}
			else{
				b[i][j+1]=a[--len];
				j++;
			}
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

