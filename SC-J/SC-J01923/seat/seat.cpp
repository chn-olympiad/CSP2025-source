#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l=1,a[15][15],r; 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(i==1&&j==1)r=a[i][j];
			else if(a[i][j]>r)l++;
		}
	}
	cout<<(int)ceil(1.0*l/n)<<" ";
	if((int)ceil(1.0*l/n)%2){
		if(l%n==0)cout<<n;
		else cout<<l%n;
	}
	else{
		if(l%n==0)cout<<1;
		else cout<<n-(l%n)+1;
	}
	return 0;
}
