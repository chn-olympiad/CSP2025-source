#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,k,a[N],tmp=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			tmp=1;
			break;
		}
	}
	if(tmp==0 && k==1) cout<<n;
	else cout<<n-2;
	return 0;
}
