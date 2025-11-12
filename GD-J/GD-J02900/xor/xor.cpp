#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int a[500010];
bool flag[500010];
int ans;
ll getxor(int l,int r){
	ll xornum=a[l];
	if(flag[l]) return -1;
	for(int i=l+1;i<=r;i++){
		if(flag[i]) return -1;
		xornum^=a[i];
	}
	return xornum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int len=0;len<=n-1;len++){
		for(int l=1;l+len<=n;l++){
			if(getxor(l,l+len)==k){
				ans++;
				for(int i=l;i<=l+len;i++) flag[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
