#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[N];
int sum[N];

map<int, int> mp;

int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin>>n>>k;
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	
	int l = 1;
	int ans = 0;
	mp[0] = 0;
	bool st = 1;
	
	for(int i = 1 ; i <= n ; i ++){
		
		int state = k ^ sum[i];
		
		if(state == 0 && mp[state] == 0 && l == 1 && st){
			l = i;
			st = false;
			ans ++;
		}
		
		if(mp[state] >= l){
			l = i;
			ans ++;
		}
		
		mp[sum[i]] = i;
	}
	
	cout<<ans;
	
	return 0;
} 
