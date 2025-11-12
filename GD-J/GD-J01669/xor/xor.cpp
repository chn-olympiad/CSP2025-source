#include<bits/stdc++.h>
using namespace std;
int n,k,j=1,ans;
int a[2000000];
int main() {
 	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]^a[j] == k){
			ans++;
			j=i+1;
		}
	}
	cout<<ans;
} 
