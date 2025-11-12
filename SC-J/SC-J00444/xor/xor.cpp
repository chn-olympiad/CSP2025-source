#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[500005];
int xsum[500005];
int query(int l,int r){return (xsum[r]^xsum[l-1]);}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		xsum[i]=xsum[i-1]^s[i];
	}
	int tknow=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=tknow+1;j<=i;j++){
			if(query(j,i)==k){
				ans+=(j>tknow);
//				cout<<tknow<<' '<<j<<'-'<<i<<'\n';
				tknow=i;
				break;
			}
		}
	}
	
	cout<<ans;
	
	
	return 0;
}