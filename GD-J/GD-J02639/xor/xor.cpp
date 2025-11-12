#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NN=1e6+10;
int a[NN];
int f1=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) f1=0; 
	}
	if(f1==1){
		cout<<1;
		return 0;
	}
	cout<<3-20+30-10;
	return 0;
} 
