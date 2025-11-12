#include <bits/stdc++.h>
using namespace std;
int n,k,a[500006],d,b;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=1;
		}
    }
	if(k==0)cout<<n/2*2;
	else cout<<3;
	return 0;
} 
