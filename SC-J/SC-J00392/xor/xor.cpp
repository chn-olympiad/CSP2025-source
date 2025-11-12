#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int k=1;k<=n;k++){ 
		for(int i=1;i<=n-k+1;i+=k){
			for(int j=i;j<=k+i-1;j++){
				sum=(sum^a[j]);
			} 
			if(sum==k)ans++;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
}
