#include <iostream>
#include <vector>
using namespace std;
int n,k,a[500005],b[500005];
vector<pair<int,int>>v,d;
int dfs(int x,int ans){
	int mx=ans;
	d.push_back(v[x]);
	int l=v[x].first,r=v[x].second;
	for(int i=x+1;i<v.size();++i){
		int nl=v[i].first,nr=v[i].second;
		if(nr<l || nl>r){
			mx=max(mx,dfs(i,ans+1));
		}
	}
	return mx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		int l;
		cin >> l;
		a[i]=a[i-1]^l;
	}
	for(int i=0;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			int l = a[j]^a[i];
			if(l==k){
				v.push_back({i+1,j});
			}
		}
	}
	int as=1;
	for(int i=0;i<v.size();++i){
		as=max(as,dfs(i,1));
	}
	cout << as;
	return 0;
}