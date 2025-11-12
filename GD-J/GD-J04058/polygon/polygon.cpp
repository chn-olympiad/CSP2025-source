#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
vector<int> vec;
set<vector<int> > st;
int a[10005];
void dfs(int id,int xz,int k){
	if(id>n||xz>k)return;
	vec.push_back(a[id]);
	st.insert(vec);
	dfs(id+1,xz+1,k);
	vec.pop_back();
	st.insert(vec);
	dfs(id+1,xz,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,1,i);
	}
	int cnt=0;
	for(auto it:st){
//		cout<<it.size()<<'\n';
		if(it.size()<3)continue;
		int sum=0,maxn=0;
		for(auto x:it){
//			cout<<x<<' ';
			sum+=x;
			maxn=max(maxn,x);
		}
//		cout<<'\n';
		if(sum>2*maxn)cnt=(cnt+1)%mod;
	}
	cout<<cnt;
	return 0;
}
