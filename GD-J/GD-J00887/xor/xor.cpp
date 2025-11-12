#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5;
int n,k;
int a[MAXN+1];
int ps[MAXN+1];
vector<pair<int,int>> sol;

int calc(int lidx,int ridx){
	if(lidx==1) return ps[ridx];
	return ps[ridx]^ps[lidx-1];
}

void work(){
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	ps[1]=a[1];
	for(int i=2;i<=n;++i){
		ps[i]=ps[i-1]^a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(calc(i,j)==k){
				sol.push_back({i,j});
				break;
			}
		}
	}
	for(int i=1;i<sol.size();++i){
		while(sol[i-1].second>=sol[i].first&&i<sol.size()){
			if(sol[i].second>sol[i-1].second) sol.erase(sol.begin()+i);
			else sol.erase(sol.begin()+i-1);
		}
	}
	cout<<sol.size();
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	work();
	return 0;
}
