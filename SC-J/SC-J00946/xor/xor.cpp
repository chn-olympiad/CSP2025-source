#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<n/2;
		return 0;
	}
	bool b=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1) b=0;
		f[i]=f[i-1]^a[i];
	}
	if(b){
		int ans=0;
		int j=2;
		for(int i=1;i<=n;i++){
			if(f[j]^f[i]==1){
				j++;
			}
			else{
				ans++;
			}
		}
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[j]^f[i]==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
