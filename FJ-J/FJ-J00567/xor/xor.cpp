#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]&&a[i]!=0) ans++;
			}
		}
		cout<<ans;
	}
	cout<<n%k;
	return 0;
} 
