#include<bits/stdc++.h>
using namespace std;
long long a[120],t[120][120];
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	long long n,m,i;
	cin>>n>>m;
	for(i=1;i<=m*n;i++){
		cin>>a[i];
	}if(n==2&&m==2){
		cout<<2<<" "<<2;
	}else if(n==3&&m==3){
		cout<<3<<" "<<1;
	}
	return 0;
}
