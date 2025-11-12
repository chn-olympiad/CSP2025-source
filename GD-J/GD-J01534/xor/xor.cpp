#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int zy=(1<<20)+10;
int lst[zy],a[N],ans;
struct node {
	int l,r;
	friend bool operator<(node a,node b) {
		return a.r<b.r;
	}
} bian[N];
int n,k,cnt,maxx=-1;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	lst[0]=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]=a[i]^a[i-1];
		int ni=a[i]^k;
		if(ni==0 && lst[0]==0) {
			bian[++cnt]= {1,i};
			lst[ni]=-1;
		} else if(lst[ni]>0) {
			bian[++cnt]= {lst[ni]+1,i};
			lst[ni]=-1;
		}
		lst[a[i]]=i;
	}
	sort(bian+1,bian+cnt+1);
	for(int i=1; i<=cnt; i++) {
		if(bian[i].l>maxx) {
			maxx=bian[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
//f**k ccf    
还是道水题吧（普及+）……       应该没有人人AC 
*/
