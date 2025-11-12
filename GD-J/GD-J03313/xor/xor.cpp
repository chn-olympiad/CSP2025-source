#include<bits/stdc++.h>
using namespace std;
#define int long long  
int n,k,a[500005],f,ans=0,s[500005];
struct node{
	int l,r;
};
bool cmp(node x,node y) {
	return x.r<y.r;
}
vector<node>v;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>=2) f=1;
	}
	if(f==0) {
		for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		cout<<ans;
	} else {
		for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				int t=s[j]^s[i-1];
				if(t==k) v.push_back({i,j});
			} 
		}
		sort(v.begin(),v.end(),cmp);
		int d=v[0].r;
		for(int i=1;i<v.size();i++) {
			if(v[i].l>d) {
				ans++;
				d=v[i].r;
			}
		}
		cout<<ans+1;
	}
	return 0;
} 
