#include<bits/stdc++.h>
using namespace std;
int n,k,l[1000001],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>l[i];
		}
		cout<<n;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>l[i];
			if(l[i]==1) sum++;
		}
		cout<<n-sum;
	}
	
	return 0;
}
