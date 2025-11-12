#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int a[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;	
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f++;
	}
	n-=f;
	if(k==0) cout<<n/2;
	else cout<<n;
	return 0;
}

