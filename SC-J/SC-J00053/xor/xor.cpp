#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<int,int> last;
vector<pair<int,int>> ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int s=0;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		s^=tmp;
		if(last.count(k^s)!=0)
			ans.push_back({last[k^s]+1,i});
		last[s]=i;
	}
	
	sort(ans.begin(),ans.end(),[](pair<int,int> a,pair<int,int> b){
		return a.first!=b.first ? a.first<b.first:a.second<b.second;
	});
	
	int lst=-1,cnt=0;
	for(int i=0;i<int(ans.size());i++){
		if(ans[i].first<=lst) 
			continue;
		lst=ans[i].second;
		cnt++;
	}
	cout<<cnt+1<<'\n';
	return 0;
}