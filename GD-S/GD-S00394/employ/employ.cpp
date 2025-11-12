#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 505
#define MOD 998244353
using namespace std;
bool f[N];
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		char c;
		cin>>c;
		f[i] = c-'0';
	}
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int tao = 0;
	
	
	return 0;
} 
