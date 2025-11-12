#include<iostream>
#include<vector>
using namespace std;
const int N = 500000+5; 
const int M = 2000000+5;
vector<int>v[M];
int a[N],p[N],maxn[N],n,k,s[N],t;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		s[i] = (s[i-1]^a[i]);
	}
	v[0].push_back(0);
	for(int i =1;i<=n;i++){
		t = (s[i]^k);
		for(int j =0;j<v[t].size();j++){
			p[i] = max(p[i],maxn[v[t][j]]+1);
		}
		maxn[i] = max(maxn[i-1],p[i]);
		v[s[i]].push_back(i);
	}
	cout<<maxn[n];
	return 0;
}
