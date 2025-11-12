#include<bits/stdc++.h>
using namespace std;
int c,r,n,m;
int p[150][150];
int l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		} 
	}
	for(int i=1;i<=m*n;i++){
		cin>>l;
	}
	sort(l+1,l+1+n);
	for(int i=1;i<=n;i++){
		if(n==i){
			p[i][j+1];
		}else{
			cout<<n<<" "<<m;
		}
	}
	return 0;
}

