#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],g[500005],f[5000][5000];
struct node{
	int l,r;
};
vector<node>s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
		f[i][i]=a[i];
	}
	vector<int>g(n+1,0);
	for(int l=0;l<n;++l)
		for(int r=l;r<n;++r){
			if(l!=r) f[l][r]=f[l][r-1]^a[r];
			if(f[l][r]==k) s.push_back({l,r});
		}
	for(int i=0;i<s.size();++i){
		for(int j=n;j>=s[i].r;--j){
			if(s[i].l>0) g[j]=max(g[j],g[s[i].l-1]+1);
			else g[j]=max(g[j],1);
		}
	}
	cout<<g[n];
	return 0;
}