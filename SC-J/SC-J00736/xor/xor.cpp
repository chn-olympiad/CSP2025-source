#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=5000+10;
int n,k,a[maxn*100],xors[maxn*100],ans,cnt,maxr;
struct node{
	int l,r;
}q[maxn*maxn];
bool cmp(node x,node y){
	if(x.r==y.r) return x.l>y.l;
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xors[i]=a[i]^xors[i-1];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((xors[j]^xors[i-1])==k){
				cnt++;
				q[cnt].l=i;
				q[cnt].r=j;
			}
	sort(q+1,q+cnt+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((xors[j]^xors[i-1])==k){
				cnt++;
				q[cnt].l=i;
				q[cnt].r=j;
			}
	for(int i=1;i<=cnt;i++)
		if(maxr<q[i].l){
			ans++;
			maxr=q[i].r;
		}
	cout<<ans<<endl;
	return 0;
}