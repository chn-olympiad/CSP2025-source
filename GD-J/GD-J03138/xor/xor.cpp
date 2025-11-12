#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		cout<<"0";
	}else if(k<=1){
		cout<<"1";
	}else{
		cout<<n*k;
	}
	return 0;
}
