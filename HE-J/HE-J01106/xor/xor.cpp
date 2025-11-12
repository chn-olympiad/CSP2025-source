#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,k,a[N],pd;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)pd=1;
	}
	if(pd==0){
	    cout<<n/2;
	    return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
	}
	cout<<ans;
	return 0;
}
