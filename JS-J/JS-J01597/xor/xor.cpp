#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500500],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1,j=i;i<=n;){
			int bj=0;
			
			while(bj!=k&&j<=n){
				bj=(bj^a[j]);
				j++;
			}
			if(bj==k){
				ans++;
				i=j;
			} 
	} 
	cout<<ans;
	return 0;
}
