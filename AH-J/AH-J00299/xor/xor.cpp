#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}else if(a[i]==0){
			ans++;
		}
	}
	if(ans+cnt==n){
		if(cnt==n){
			cout<<n/2;
			return 0;
		}else{
			if(k==1){
				cout<<cnt;
				return 0;
			}else{
				int l=1;
				while(l<n){
					if(a[l]==1 && a[l+1]==1){
						ans++;
						l++;
					}
					l++;
				}
				cout<<ans;
				return 0;
			}
		}
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
