#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6;
int n,k,cnt,jj,a[N],sum[N],ans=1;
struct st{
	int l,r;
}b[N];
bool cmp(st c,st d){
	if(c.r!=d.r) return c.r<d.r;
	return c.l>d.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		if(a[i]==k) b[++jj]={i,i};
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				b[++jj].l=i;
				b[jj].r=j;
				break;
			}
		}
	}
	sort(b+1,b+1+jj,cmp);
	int last=1;
	for(int i=2;i<=jj;i++){
		if(b[i].l>b[last].r){
			ans++;
			last=i;
		}
	}
	printf("%d",ans);
	return 0;
}
