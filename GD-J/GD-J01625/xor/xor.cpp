#include<bits/stdc++.h>
#define ui unsigned int
using namespace std;
const int N=5e6;
ui n,k,a[N],xo[N];
vector<pair<int,int>>may,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=i;i<=n;++i) xo[i]=xo[i-1]^a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if((xo[j]^xo[i-1])==k){
				may.push_back({i,j});
				break;
			}
		}
	}
	if(may.empty()){
		cout<<0<<endl;
		return 0;
	} 
	ans.push_back(may[0]);
	for(int i=1;i<may.size();++i){
		if(may[i].first>ans.back().second){
			ans.push_back(may[i]);
		}
		else if(may[i].second<ans.back().second)
			ans[ans.size()-1]=may[i];
	}
	cout<<ans.size()<<endl;
	return 0;
}

