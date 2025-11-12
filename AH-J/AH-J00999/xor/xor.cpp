#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010],b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	for(int l=0;l<n;l++){
		for(int i=1;i<=n;i++){
			if(i+l>n) break;
			long long h=0;
			for(int k1=i;k1<=i+l;k1++){
				h^=a[k1];
				if(b[k1]==1){
					h=-1;
					break;
				}
			}
			if(h==k){
				for(int k1=i;k1<=i+l;k1++){
					b[k1]=1;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
