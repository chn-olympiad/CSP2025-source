#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[200005],x[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=(x[i-1]^a[i]);
	}
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=s;j--){
			if((x[i]^x[j])==k){
				s=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
}

