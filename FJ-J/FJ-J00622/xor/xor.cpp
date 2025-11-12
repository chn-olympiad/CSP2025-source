#include <bits/stdc++.h>
using namespace std;

int n,k,m;
long long maxn;
bool ab[5005][5005][25],sumb[5005][5005];
int ai[5005][5005];

void devide(int num){
	for(int i = 19;i >= 0;i--){
		int p = pow(2,i);
		ab[num][num][i] = m/p;
		ai[num][num] += m/p*p;
		m %= p;
	}
}

void f(int num){
	for(int i = num-1;i >= 1;i--){
		for(int j = 0;j <= 19;j++){
			if(ab[i+1][num][j] == ab[i][i][j])
				ab[i][num][j] = 0;
			else 
				ab[i][num][j] = 1;
		}
		for(int j = 0;j <= 19;j++)
			if(ab[i][num][j])
				ai[i][num] += pow(2,j);
	}
}

void dfs(long long s,int l){
	if(s+n-l <= maxn) return;
	else if(l == n){
		maxn = max(maxn,s);
		return;
	}
	for(int i = l+1;i <= n;i++)
		if(sumb[l+1][i]){
			dfs(s+1,i);
		}
	dfs(s,l+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> m;
		devide(i);
		f(i);
	}
	for(int i = 1;i <= n;i++)
		for(int j = i;j <= n;j++)
				sumb[i][j] = ai[i][j] == k;
	dfs(0,0);
	cout << maxn;
	
	return 0;
}
