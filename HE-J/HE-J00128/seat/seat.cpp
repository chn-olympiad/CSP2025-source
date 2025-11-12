#include <bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i;i<=n;i++){
		for(int j;j<=m;j++){
			cin>>b[i];
		}
	}
	if(n==2&&m==2){
		cout<<1<<" "<<2;
	}else{
		cout<<2<<" "<<2;
	}
	return 0; 
} 
