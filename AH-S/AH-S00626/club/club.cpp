#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int x,y,z;
	int b,maxx1,maxx2,o,cha;
}a[100005];
inline int mx(int h,int g){
		return h>g?h:g;
}
bool cmp(node k,node l){
	if(k.cha==l.cha){
		return k.maxx1>l.maxx1;
	}
	return k.cha>l.cha;
}
int c[5],cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		cnt[1]=cnt[2]=cnt[3]=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			c[1]=a[i].x,c[2]=a[i].y,c[3]=a[i].z;
			sort(c+1,c+4);
			if(a[i].x==c[3])a[i].maxx1=a[i].x,a[i].b=1;
			if(a[i].y==c[3])a[i].maxx1=a[i].y,a[i].b=2;
			if(a[i].z==c[3])a[i].maxx1=a[i].z,a[i].b=3;
			if(a[i].x==c[2])a[i].maxx2=a[i].x,a[i].o=1;
			if(a[i].y==c[2])a[i].maxx2=a[i].y,a[i].o=2;
			if(a[i].z==c[2])a[i].maxx2=a[i].z,a[i].o=3;
			a[i].cha=a[i].maxx1-a[i].maxx2;
		}
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;++i){
			if(cnt[a[i].b]<n/2){
				ans+=a[i].maxx1;
				cnt[a[i].b]++;
			}
			else{
				cnt[a[i].o]++;
				ans+=a[i].maxx2;
			}
		}
		printf("%d\n",ans);
	}
	return  0;
}
