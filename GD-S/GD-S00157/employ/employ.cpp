#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500 + 50,M = 5e6 + 50,mod = 998244353;
int read(){
	int a = 1,x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') a = -1;
		ch = getchar();
	} 
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return a * x;
}
int c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	clock_t bg = clock();
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f = true;
	vector<int> v;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		f &= s[i - 1] == '1';
		v.push_back(i);
	}
	s = " " + s;
	
/*	if(f){
		int res = 1;
		for(int i=1;i<=n;i++){
			res = 1ll * res * i % mod;
		}
		cout<<res;
	}
	*/
	int res = 0;
	do{
		int sc = 0,fa = 0;
		for(int i=1;i<=n;i++){
			if(fa < c[v[i - 1]] && s[i] == '1') sc++;
			else fa++;
//			cerr<<c[v[i - 1]]<<" \n"[i==n];
		}	
		
		res += sc >= m; 
	}while(next_permutation(v.begin(),v.end()));
	cout<<res;
	clock_t ed = clock();
//	cerr<<'\n'<<double(ed - bg) / CLOCKS_PER_SEC;
	return 0;
}
