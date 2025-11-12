#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
long long k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1)
	if(k==0){
		for(int i=1;i<=n;i++)if(a[i]==0)ans++;
		cout<<ans;
	}else if(k==1){
		for(int i=1;i<n;i++){
			if(a[i]==1){
				if(a[i+1]==1){
					ans+=2;
					i++;
				}else ans++;
			}else if(max(a[i],a[i+1])-min(a[i],a[i+1])==1&&min(a[i],a[i+1])%2==0){
				ans++;
				i++;
			}
		}
	}
	return 0;
}
