#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5e5+10;
int n,k,cnt,ans;
int a[N],sum[N];
struct node{
	int l,r;
}g[N];
bool cmp(node a,node b){
	if(a.r!=b.r) return a.r<b.r;
	else return a.l>b.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
		cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int m=sum[j]^sum[i-1];
			if(m==k) g[++cnt]={i,j};
		}
	sort(g+1,g+cnt+1,cmp);
	int rr=0;
	for(int i=1;i<=cnt;i++){
		if(g[i].l<=rr) continue;
		ans++,rr=g[i].r;
	}
	cout<<ans;
	return 0;
} 