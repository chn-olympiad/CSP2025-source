#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+2;
int t;
int club(int a,int b,int c){
	if(a>=b && a>=c) return 0;
	if(b>=c) return 1;
	return 2;
}
int check(int a,int b,int c,int n){
	if(a>(n/2)) return 0;
	if(b>(n/2)) return 1;
	if(c>(n/2)) return 2;
	return -1;
}
void solve(){
	int n,a[N][3],s;
	vector<int> g[3];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int idx=club(a[i][0],a[i][1],a[i][2]);
		g[idx].push_back(i);
		s+=a[i][idx];
	}
	int k=check(g[0].size(),g[1].size(),g[2].size(),n);
	if(k==-1){
		cout<<s;
		return;
	}
	vector<int> r;
	for(auto it:g[k]){
		int mx=-1;
		for(int i=0;i<3;i++){
			if(i==k) continue;
			mx=max(mx,a[it][i]);
		}
		r.push_back(a[it][k]-mx);
	}
	sort(r.begin(),r.end());
	for(int i=0;i<g[k].size()-(n/2);i++) s-=r[i];
	cout<<s;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}
