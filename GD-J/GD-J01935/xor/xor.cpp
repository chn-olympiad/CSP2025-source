#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],x[maxn];
int n,k,ans;
int mp[maxn<<2];
int main(){//Why do I thought for even a second about 0-1 Trie
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	int qr=n,ql=n;
	for(int l=n-1;l>=0;l--){
		if(mp[x[l]^k]){
			int r=mp[x[l]^k];
			if(r<=ql){
				ans++;
				ql=l,qr=r;
			}
		}
		mp[x[l]]=l;
	}
	cout<<ans<<endl;
	return 0;
}
//CSP-S RP++!luoguUID:513746
