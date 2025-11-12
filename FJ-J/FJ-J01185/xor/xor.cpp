#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node {
	int l,r,cha;
} e[N],p[N];
int tot;
vector<int>v[1000005];
int a[N];
bool cmp(node t1,node t2) {
	if(t1.cha==t2.cha)return t1.l<t2.l;
	return t1.cha<t2.cha;
}
int ans;
int n,k;
int cnt;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)a[i]=a[i-1]^a[i];
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	v[0].push_back(0);
	for(int i=1; i<=n; i++) {
		int t=a[i]^k;
		if(v[t].size()) {
			for(auto x:v[t]) {
				e[++tot].l=x+1;
				e[tot].r=i;
				e[tot].cha=e[tot].r-e[tot].l+1;
			}
		}
		v[a[i]].push_back(i);
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1; i<=tot; i++) {
		bool f=0;
		for(int j=1; j<=cnt; j++) {
			if((e[i].l>=p[j].l&&e[i].l<=p[j].r)||(e[i].r<=p[j].r&&e[i].r>=p[j].l)||(e[i].l>=p[j].l&&e[i].r<=p[j].r)||(e[i].l<=p[j].l&&e[i].r>=p[j].r)) {
				f=1;
				break;
			}
		}
		if(!f) {
			ans++;
			p[++cnt].l=e[i].l;
			p[cnt].r=e[i].r;
		}
		//cout<<e[i].l<<" "<<e[i].r<<endl;
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
