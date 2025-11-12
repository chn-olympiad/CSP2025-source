#include <bits/stdc++.h>
using namespace std;
int n,k,a[500100],cnt,l,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l++;
		if(a[i]==1)cnt++;
	}
	if(k==0&&l==cnt){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=l;i++){
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
			if(a[i]==0){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=l;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
