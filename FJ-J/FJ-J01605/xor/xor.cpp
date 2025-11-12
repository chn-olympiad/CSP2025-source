#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		for(int j=i;j<=n;j++){
			if(cnt==k){
				ans++;
				break;
			}
			cnt^=a[j];
		}
	}
	cout<<ans;
}
