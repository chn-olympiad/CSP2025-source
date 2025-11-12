#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n,k,ans;
int a[N];
int xarr[N];
vector<pair<int,int>> qj;

int gn(int l,int r){
	return xarr[r]^xarr[l-1];
}
bool ck(int l,int r){
	for(int p=0;p<qj.size();p++){
		if(l<=qj[p].second&&r>=qj[p].first) return 0;
	}
	return 1;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xarr[i]=xarr[i-1]^a[i];
		if(a[i]==k){
			ans++;
			qj.push_back({i,i});
		}
	}
	for(int len=2;len<=n;len++){
		for(int l=n-len+1;l>=1;l--){
			int r=l+len-1;
			if(gn(l,r)==k&&ck(l,r)){
				ans++;
				qj.push_back({l,r});
			}
		}
	}
	cout<<ans;
	return 0;
}
