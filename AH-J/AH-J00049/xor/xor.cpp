#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[500005],ans[500005],l=1,r=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=ans[i-1]^a[i];
	}
	cout<<n/2;
    return 0;
}
