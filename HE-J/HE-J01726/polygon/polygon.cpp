#include<bits/stdc++.h>
using namespace std;
int n;
int a[100],da;
long long num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		da=max(da,a[i]);
		num+=a[i];
	}
	if(n<3) cout<<0<<endl;
	else {
		if(num>2*da) cout<<1;
		else cout<<0;
	}
	return 0;
} 
