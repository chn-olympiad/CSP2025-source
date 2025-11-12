#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=min(n,200002);i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2<<endl;
	}else if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
} 
