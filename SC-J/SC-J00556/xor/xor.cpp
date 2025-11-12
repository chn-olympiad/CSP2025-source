#include <bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
map<int,vector<int>> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,lst=1e9,ans=0;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		s[i] = s[i-1]^a[i];
		mp[s[i]].push_back(i);
	}
	for(int i = n;i >= 1;i--){
		if(!mp.count(k^s[i-1])){
			continue;
		}
		auto p = lower_bound(mp[k^s[i-1]].begin(),mp[k^s[i-1]].end(),i);
		if(p == mp[k^s[i-1]].end()) continue;
		if(*p<lst){
			//cout<<"["<<i<<","<<*p<<"]\n";
			lst = i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}