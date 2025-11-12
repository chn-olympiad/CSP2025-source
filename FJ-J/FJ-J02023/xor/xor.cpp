#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int a[MAXN];
struct node {
	int sxor;
	int l,r;
}tmp; 
vector<node> b;
vector<node> c; 
bool cmp(node aa,node bb) {
	return aa.r<bb.r;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		int tot=a[i];
		for (int j=i+1;j<=n;j++) {
			tot^=a[j];
			tmp.sxor=tot; tmp.l=i; tmp.r=j;
			b.push_back(tmp);
		}    
	} 
	for (int i=1;i<=n;i++) {
		tmp.l=tmp.r=i;
		tmp.sxor=a[i];
		b.push_back(tmp);
	}
	int szb=b.size();
	for (int i=0;i<szb;i++) {
		tmp=b[i];
	}
	for (int i=0;i<szb;i++) {
		tmp=b[i];
		if (tmp.sxor==k) {
			c.push_back(tmp);
		}
	}
	sort(c.begin(),c.end(),cmp);
	int ans=0,lst=c[0].r;
	for (int i=1;i<(int)c.size();i++) {
		tmp=c[i];
		if (c[i].l<=lst) {
			ans++;
		}else {
			lst=c[i].r;
		}
	}
	int u=c.size();
	int anss=u-ans;
	cout<<anss<<'\n';
	return 0;
}
