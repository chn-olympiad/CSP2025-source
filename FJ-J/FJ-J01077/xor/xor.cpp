#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+2;
int n,k;
int a[MAXN];
long long tree[MAXN<<2];
void add(int p,int val){
	while(p<=n){
		tree[p]^=val;
		p+=p & -p;
	}
}
long long query(long long p){
	long long res=0;
	while(p){
		res^=tree[p];
		p-=p & -p;
	}
	return res;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add(i,a[i]);
	}
	long long ans=0;
	vector<pair<int,int>> couts;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=1;
			for(auto t : couts){
				int l=t.first,r=t.second;
				if((i<=l&&j>=r)||(i>=l&&j<=r)){
					flag=false;
					break;
				}
			}
			if(!flag) continue;
			if(query(j)-query(i-1)==k||a[i]==k){
				ans++;
				couts.push_back({i,j});
			}
		}
	}
	cout<<ans;
	return 0;
}
