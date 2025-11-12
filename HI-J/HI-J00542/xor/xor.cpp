#include <bits/stdc++.h>
using namespace std;
int n,k,a[10005],a1,a0,a2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) a1++;
		else a0++;
	}
	if(k==1){
		cout<<a1;
	}
	else if(k>1){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				a2++;
			}
		}
		cout<<a2;
	}
	else{
		cout<<a0;
	}
	return 0;
}
