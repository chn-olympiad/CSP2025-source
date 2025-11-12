#include<bits/stdc++.h>
using namespace std;
int n,k,a[200010],f1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f1=1;
		}
	}
	if(f1==0&&k==0){
		cout<<n;
		return 0;
	}
	return 0;
}
