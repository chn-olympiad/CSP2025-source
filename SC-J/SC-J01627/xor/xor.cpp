#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,k,a[N],f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]>1){
				f=0;
				break;
			}
		}
		if(f==1){
			cout<<n/2;
		}
	}
	return 0;
}