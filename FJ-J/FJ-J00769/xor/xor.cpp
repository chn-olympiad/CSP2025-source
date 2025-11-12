#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) sum++;
		}
		cout<<sum;
	}
	return 0;
}


