#include<stdio.h>
#include<algorithm>
int n,k;
int a[500010];
int f[500010];
typedef struct node{
	int l,r;
	friend bool operator<(node n1,node n2){
		return n1.r<n2.r;
	}
}node;
node p[500010];
void c3(){
	int cnt=0,ans=0,pl=0,pr=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((f[j]^f[i-1])==k){
				p[++cnt].l=i;
				p[cnt].r=j;
				break;
			}
		}
	}
	std::sort(p+1,p+1+cnt);
	int ll=-1;
	for(int i=1;i<=cnt;i++){
		if(p[i].l>ll){
			ll=p[i].r;
			ans++;
		}
	}
	printf("%d",ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	c3();
	return 0;
}