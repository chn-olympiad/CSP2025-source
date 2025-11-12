#include<bits/stdc++.h>
using namespace std;
int n,k,a[512345],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int f=a[i];
		if(f==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			f=f^a[j];
			if(f==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
