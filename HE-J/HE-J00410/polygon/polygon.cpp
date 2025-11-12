#include<iostream>
#include<algorithm>
#include<random>
#include<iomanip>
#include<vector>
using namespace std;
const int MAXN =  5005;
const int modn = 998244353;
int a[MAXN],n,ans;
vector<int> path;
vector<vector<int>> result;
void dfs(int k){
	if(!path.empty()&&path.size()>=3){
		vector<int> vec;
		for(int j = 0;j<path.size();j++){
			vec.push_back(a[path[j]]);
		}
		sort(vec.begin(),vec.end());
		int maxi = vec[vec.size()-1];
		int cnt = 0;
		for(int i = 0;i<vec.size();i++){
			cnt+=vec[i];
		}
		if(cnt>maxi*2){
			ans = (ans+1)%modn;
		}
	}
	for(int i = k;i<=n;i++){
		path.push_back(i);
		dfs(i+1);
		path.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
