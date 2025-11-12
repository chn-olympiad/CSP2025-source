#include<bits/stdc++.h>
using namespace std;
int n,m;
int a2=0;
int s[15][15];
int a[105];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	int con=n*m;
	for(int i=1;i<=con;i++){
		cin>>a[i];
		if(i==1)a2=a[i];
	}
	int q=0;
	for(int i=2;i<=con;i++){
		for(int j=2;j<=con;j++){
			if(a[j]>a[j-1]){
		q=a[j-1];a[j-1]=a[j];a[j]=q;
		}
	}
	}
	int x=1;
	for(int i=1;i<=m;i++){
	if(i%2==1){
		for(int j=1;j<=n;j++){
			s[i][j]=a[x++];
			if(s[i][j]==a2){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	else {
		for(int j=n;j>=1;j--){
			s[i][j]=a[x++];
			if(s[i][j]==a2){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}	
	}
	return 0;
}