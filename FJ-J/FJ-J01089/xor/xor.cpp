#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		int sum=0;
		for(int j=i+1;j<=n;j++){
			if(x==k){
				sum++;
				i=j-1;
				break;
			}
			x^=a[j];
		}
		ans=max(sum,ans);
	}
	cout<<ans+1;
	return 0;
}
