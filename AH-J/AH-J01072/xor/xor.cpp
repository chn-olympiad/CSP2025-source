#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1) cout<<a[0];
	else if(n==2){
		a[0]=max(a[0],a[1]);
		cout<<a[0];
	}
    return 0;
}
