#include<bits/stdc++.h>
using namespace std;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		i<=n*m;
		a[i]=i;
		a[i]=n*m*-i+1;
		cout<<a[i];
	}
	return 0;
} 
