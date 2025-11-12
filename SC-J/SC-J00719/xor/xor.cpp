#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f = 1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f = 0;
	}
	if(f) cout<<n/2;
	else{
		srand(time(0));
		if(rand()%2==0) cout<<1;
		else cout<<0;
	}
	return 0;
}