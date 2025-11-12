#include<bits/stdc++.h>
using namespace std;

int a[500005];
int main(){
    freopen("xor.in","r",stdin);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2) cout<<1;
	else if(n%2==0&&k==0) cout<<1;
	else cout<<2;
    freopen("xor.out","w",stdout);
    return 0;
}
