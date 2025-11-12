#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,ans,cnt,pre,a[500005],p[500005],s[2000005],tag[2000005];
struct node{
	int l,r;
}h[1000005];
bool cmp(node a,node b){
	return a.r - a.l < b.r - b.l;
}
void add(int l,int r,int k){
	tag[k] = 1;
	s[k] += r-l+1;
}
void pushdown(int l,int r,int k){
	if(!tag[k]) return ;
	int mid = (l + r) >> 1;
	add(l,mid,2*k);
	add(mid+1,r,2*k+1);
	tag[k] = 0;
}
void update(int l,int r,int k,int x,int y){
	if(r < x || y < l) return ;
	if(x <= l && r <= y){
		add(l,r,k);
		return ;
	}
	pushdown(l,r,k);
	int mid = (l + r) >> 1;
	update(l,mid,2*k,x,y);
	update(mid+1,r,2*k+1,x,y);
	s[k] = s[2*k] + s[2*k+1];
}
bool query(int l,int r,int k,int x,int y){
	if(r < x || y < l) return true;
	if(x <= l && r <= y){
		if(s[k] != 0){
			return false;
		}
		return true;
	}
	pushdown(l,r,k);
	int mid = (l + r) >> 1;
	return query(l,mid,2*k,x,y) && query(mid+1,r,2*k+1,x,y);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		p[i] = p[i-1] ^ a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if((p[j] ^ p[i-1]) == k){
				h[++cnt] = {i,j};
			}
		}
	}
	sort(h+1,h+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++){
		if(query(1,n,1,h[i].l,h[i].r)){
			update(1,n,1,h[i].l,h[i].r);
			ans ++;
		}
	}
	printf("%d",ans);
	return 0;
}
