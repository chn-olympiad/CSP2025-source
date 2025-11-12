#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		if(cnt==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			cnt^=a[j];
			if(cnt==k){
				i=j+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
