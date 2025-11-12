#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+5, mod = 998244353;
int n, cnt = 0, cnt0 = 0;
int a[MAXN];
vector<int> v;
bool flag = true;


int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 1) cnt0++;
	}
	
	cout << cnt0*(cnt0-1)/2;
	
	return 0;
}