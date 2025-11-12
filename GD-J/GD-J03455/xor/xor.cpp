#include<bits/stdc++.h>
using namespace std;
int a[500100],b[500100];
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	cin>>b[1];
	a[1]=b[1];
	for(int i=2;i<=n;i++){
		cin>>b[i];
		a[i]=a[i-1]^b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((a[i]^a[j]^b[j])==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
