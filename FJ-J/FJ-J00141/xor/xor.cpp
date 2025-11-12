#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int l,r;
}q[1000001];
int a[1000001],f[1000001];
int cmp(node a,node b){
	if(a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,cnt=0,ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=a[i];
		if(f[i]==m){
			q[++cnt].l=i;
			q[cnt].r=i;
			continue;
		}		
		for(int j=i-1;j>=1;j--){
			f[i]=f[i]^a[j];
			if(f[i]==m){
				q[++cnt].l=j;
				q[cnt].r=i;	
				break;			
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int l=1;
	while(1){
		if(l>cnt) break;
		int flag=0;
		ans++;
		int lst=q[l].r;
		l++;
		while(q[l].l<=lst){
			l++;
			if(l>cnt){
				flag=1;
				break;
			}
		}
		if(flag==1) break;
	}
	printf("%lld",ans);
	return 0;
}
