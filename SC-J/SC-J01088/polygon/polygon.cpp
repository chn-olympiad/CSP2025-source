#include<bits/stdc++.h>
using namespace std;
#define M 998244353
int n,k;
vector<int>a(5000,0);
void dfs(int x,int l,int m,int s){
	for(int i=x+1;i<n;++i)
		if(l>1){
			s+=a[i];
			m=max(m,a[i]);
			if(s>m*2){
				k=(k+1)%M;
				dfs(i,l+1,m,s);
			}
		}
		else dfs(i,l+1,max(m,a[i]),s+a[i]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) dfs(i,1,a[i],a[i]);
	cout<<k;
	return 0;
}