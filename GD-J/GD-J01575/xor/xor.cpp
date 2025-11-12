#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans,m=0,jend;
	cin>>n>>k;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	vector<pair<int,int>> area;
	for(int i=0;i<n;i++){
		ans=num[i];
		if(ans==k){
			area.push_back({i,i});
			continue;
		}
		for(int j=i+1;j<n;j++){
			ans^=num[j];
			if(ans==k){
				area.push_back({i,j});
				break;
			}
		}
	}
	for(int i=0;i<n;i++,m++){	
		jend=n;
		for(auto j:area){
			if(j.first>=i&&j.second<jend){
				jend=j.second;
			}
		}
		i=jend;
		if(i==n){
			break;
		}
	}
	cout<<m;
	return 0;
}
