#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000006];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,o=0;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) o++;
	}o++;
	int b=o/n+1;
	if(o%n==0){
		b--;
	}int c=o%n;
	if(c==0) c=n;
	if(b%2==0){
		cout<<b<<" "<<n-c+1;
	}else{
		cout<<b<<" "<<c;
	}
	return 0;
}

