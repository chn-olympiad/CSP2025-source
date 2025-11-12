#include<bits/stdc++.h>
using namespace std;
int n,k,ans,flag=1;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
	}
	if(flag){
		if(k>1){
			cout<<0;
			return 0;
		}
		if(k==1){
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		}
		else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) cnt=0,ans++;
				if(a[i]==1) cnt++;
				if(cnt==2){
					ans++;
					cnt=0;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;){
		long long tmp=a[i];
		bool f=0;
		for(int j=i+1;j<=n;j++){
			if(tmp==k){
				ans++;
				i=j;
				f=1;
				break;
			}
			tmp^=a[j];
		}
		if(tmp==k){
			ans++;
			cout<<ans;
			return 0;
		}
		if(!f) i++;
	}
	cout<<ans;
	return 0;
}
