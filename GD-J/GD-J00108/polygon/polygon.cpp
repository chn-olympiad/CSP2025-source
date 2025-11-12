#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,l,ans;
vector<int> a(5005),b(5005),s(5005),c(5005);
void dfs(int x,int sum,int f) {
	if(x==f+1) return ;
	for(int i=((x==f)?1:0);i<=s[x];i++) {
		if(sum+i*b[x]>2*b[f]) 
			ans=(ans+1)%mod;
		dfs(x+1,sum+i*b[x],f);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin()+1,b.begin()+1+n);
	l=unique(b.begin()+1,b.begin()+1+n)-b.begin()-1;
	for(int i=1;i<=n;i++) {
		int t=lower_bound(b.begin()+1,b.begin()+1+l,a[i])-b.begin();
		s[t]++;
	}
	for(int i=3;i<=l;i++) {
		dfs(1,0,i);
	}
	cout<<ans;
	
	return 0;
}
