#include <bits/stdc++.h>
const int MAX = 998244353;
using namespace std;

vector<int> nums;
vector<int> c;
int n,ans=0;
void isv(){
	if(c.size() < 3) return;
	int s=0,m=-1;
	for(int i = 0;i<c.size();i++){
		if(c[i] > m) m = c[i];
		s += c[i];
	}
	if(s > 2*m){
//		for(int i = 0;i<c.size();i++)printf("%d ", c[i]);
//		printf("\n");
		ans++;
		ans = ans % MAX;
	}
}

void f(int x){
	if(x >= n){
		isv();
		return;
	}
	f(x+1);
	c.push_back(nums[x]);
	f(x+1);
	c.pop_back();
};

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d", &x);
		nums.push_back(x);
	}
	f(0);
	printf("%d", ans);
	return 0;
}
