#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			f1=0;
		}
	}
	if(f1==1&&k==0){
		cout<<n/2;
		return 0;
	}
	return 0;
}
