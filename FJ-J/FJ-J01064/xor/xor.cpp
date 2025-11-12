#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum++;
				continue;
			}
			if(a[i]==a[i+1]){
				sum++;
				i+=1;
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
