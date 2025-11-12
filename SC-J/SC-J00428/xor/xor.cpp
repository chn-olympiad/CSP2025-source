#include<bits/stdc++.h>
#define int long long 
using namespace std;
map<pair<int,int>,int> mp;
map<int,int> mp1;
int n,k,ans=0,a[500010],b[500010];
bool vist[500010];
void check(int l,int r){
	for(int i=l;i<=r;i++) vist[i]=1;
}
bool solve(int l,int r){
	for(int i=l;i<=r;i++){
		if(vist[i]) return 0;
	}
	return 1;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ont","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vist[0]=0;b[0]=0;mp1[0]++;mp[{0,1}]=0;
	cin>>n>>k; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
		mp1[b[i]]++;
		mp[{b[i],mp1[b[i]]}]=i;
	} 
	for(int i=1;i<=n;i++){
		if(vist[i]) continue;
		int mi=k^b[i];
		for(int j=1;j<=mp1[mi];j++){
			int u=mp[{mi,j}];
			if(solve(u+1,i)&&u+1<=i){
				ans++;
				check(u+1,i);
			}	
		}
	}
	cout<<ans;
	return 0;
}