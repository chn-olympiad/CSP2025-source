#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],cnt=0,ans;
struct Node{
	int l,r;
}f[1000003];
bool cmp(Node p,Node q){
	if(p.r==q.r)return p.l>q.l;
	return p.r<q.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int t=a[i];
		if(t==k){
			f[++cnt].l=i;
			f[cnt].r=i;
		}
		for(int j=i+1;j<=n;j++){
			t^=a[j];
			if(t==k){
				f[++cnt].l=i;
				f[cnt].r=j;
			}
		}
	}
	sort(f+1,f+1+cnt,cmp);
	int h=0;
	ans=0;
	for(int i=1;i<=cnt;i++){
		if(f[i].l>h){
			ans++;
			h=f[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
