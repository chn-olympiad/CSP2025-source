#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,kom;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}else if(a[i]==a[i+1]&&i!=n){
				ans++;
				i++;
			}
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}else if(a[i]%2==0&&a[i+1]==a[i]+1){
				ans++;
				i++;
			}
		}
	}else{
		for(int i=1;i<n;i++){
			kom=a[i];
			if(a[i]==k){
				ans++;
				continue;
			}
			for(int j=i+1;j<=n;j++){
				kom=kom^a[j];
				if(a[j]==k){
					break;
				}
				if(kom==k){
					ans++;
					i=j;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
