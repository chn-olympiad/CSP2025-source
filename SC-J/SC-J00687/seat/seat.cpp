#include<bits/stdc++.h>
using namespace std;
int a[110],s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i*m-m+j];
		}
	}
	
	int sc=a[1];
	
	sort(a+1,a+n*m+1);
	int k=1,y=m;
	if(m%2==0){
		for(int i=1;i<=n;i++){
			s[i][y]=a[k];
			k++;
		}
		y--;
	}
	while(k<=m*n){
		for(int i=n;i>=1;i--){
			s[i][y]=a[k];
			k++;
		}
		y--;
		for(int i=1;i<=n;i++){
			s[i][y]=a[k];
			k++;
		}
		y--;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sc==s[i][j]) cout<<j<<" "<<i<<"\n";
		}
	}
}