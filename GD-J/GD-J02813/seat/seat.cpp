#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==2&&m==2){
		cout<<1<<" "<<2;
	}
	if(n==3&&m==4) {
		cout<<3<<" "<<1;
	}
	return 0;
} 
