#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt;
vector<long long> h;
void dfs(long long p, long long k, long long sum, long long maxn,vector<long long> l){
	if(p > n*2)return;
	
//	for(long long i = 0; i < (int)l.size(); i++){
//		cout << l[i] << ' ';
//	}
//	cout << endl;
	l.push_back(a[p]);
	maxn = max(maxn,a[p]);
	sum+=a[p];
//	cout << sum << k << endl;
	if(sum > 2*maxn && k>=3){
//		cout << "answer: ";
//		for(long long i = 0; i < (int)l.size(); i++){
//			cout << l[i] << ' ';
//		}
//		cout << endl;
		cnt++;
		return;
	}
	for(long long i = 1; i <= n*2; i++){
		dfs(p+i,k+1,sum,maxn,l);
	}
}
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		dfs(i,1,0,0,h);
	}
	cout << cnt;
	return 0;
}
