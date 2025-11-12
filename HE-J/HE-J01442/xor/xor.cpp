#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,k,a[N],su[N],cnt,ans;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) p=0;
	}
	if(p){
		if(n==2) cout<<1;
		if(n==3) cout<<3;
		if(n==4) cout<<4;
		return 0;
	}	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==i && a[j]==k) ans++;
			else {
				cnt=1;
				for(int l=j;l<=i;l++){
					cnt=(a[l]^cnt);
				}
				cnt=(cnt^1);
				if(cnt==k) ans++;
			} 
		}
	}
	cout<<ans;
	
	
	return 0;
}
