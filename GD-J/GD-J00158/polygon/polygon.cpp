#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
vector<unsigned long long> stair;
map<int, int> pool, used;

unsigned long long getStair(unsigned x){
	if(!stair.size()){
		stair.resize(1);
		stair[0] = 1;
	}
	if(x<stair.size()) return stair[x];
	stair.reserve(x+1);
	for(int i=stair.size();i<=x;i++){
		stair.emplace_back(stair[i-1]*i);
	}
	return stair[x];
}

int bruteforce(int number, int count, int max, int sum, int sumCount){
//	cout << "{\n'command': 'bruteforce(" << number << ", " << count << ", " << max << ", " << sum << ")',\n";
	sum += number*count;
	sumCount ++;
	int avaliable = pool[number];
	int ret = sum>=max*2 && sumCount>=3;
//	cout << "'structure': [\n";
	for(auto x : pool){
		if(x.first<=number || x.first > max) continue;
		for(int i=1;i<=x.second;i++){
			ret= (ret + bruteforce(x.first, i, max, sum, sumCount))%998244353;
		}
	}
	int multiply = getStair(avaliable)/getStair(avaliable-count) % 998244353;
	int retv = ret*multiply%998244353;
//	cout << "],\n'multiply': " << multiply << ",\n'retv': " << retv << ",\n},\n";
	return retv;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		pool[t] = pool[t] + 1;
	}
	
//	cout << "["; 
	int ans = 0;
	for(auto &x : pool){
		for(int i=1;i<=pool.begin()->second;i++){
//			cout << "{\n'structure': ";
			ans = (ans+bruteforce(pool.begin()->first, i, x.first, 0, 0))%998244353;
//			cout << "\n'value': " << ans << ",\n},\n";
		}
	}
//	cout << "]";
	
	cout << ans;
	
	return 0;
}
