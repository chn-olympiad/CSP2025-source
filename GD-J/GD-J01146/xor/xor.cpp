#include<bits/stdc++.h>
using namespace std;
int n,k,ans,r=-1;
int a[50009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++) a[i]=a[i-1]^a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if((a[j-1]^a[i])==k&&j>r){
				ans++;
				r=i;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
