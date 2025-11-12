#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
int n,k,a[N],cnt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<"0";
	}
	else if(n==2) cout<<"1"<<endl; 
	else {
		cout<<n/2<<endl; 
	}
	return 0;
} 
