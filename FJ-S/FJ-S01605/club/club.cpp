#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
	int v,pos;
}p[5];
struct pp{
	node a,b,c;
	int s1,s2;
	bool operator < (pp A){
		return s1>A.s1;
	}
}a[MAXN],c[MAXN];
int n,t,num[MAXN],len;
long long ans;
bool cmp(pp A,pp B){
	return A.s2>B.s2;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t--;){
		scanf("%d",&n);
		len=0;
		ans=0;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[1].v,&p[2].v,&p[3].v);
			p[1].pos=1,p[2].pos=2,p[3].pos=3;
			for(int j=1;j<=2;j++){
				for(int k=j+1;k<=3;k++){
					if(p[j].v>p[k].v){
						swap(p[j],p[k]);
					}
				}
			} 
			a[i].a=p[3];
			a[i].b=p[2];
			a[i].c=p[1];
			a[i].s1=a[i].a.v-a[i].b.v;
			a[i].s2=a[i].b.v-a[i].c.v;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
								//								printf("%d,%d %d,%d %d,%d\n",a[i].a.v,a[i].a.pos,a[i].b.v,a[i].b.pos,a[i].c.v,a[i].c.pos);
			if(num[a[i].a.pos]<n/2){
				num[a[i].a.pos]++;
				ans+=a[i].a.v;
			}else{
				c[++len]=a[i];
			}
		}
		sort(c+1,c+len+1,cmp);
		for(int i=1;i<=len;i++){
			if(num[c[i].b.pos]<n/2){
				num[c[i].b.pos]++;
				ans+=c[i].b.v;
			}else{
				num[c[i].c.pos]++;
				ans+=c[i].c.v;
			}
		}
		printf("%lld\n",ans);
	}
					//	printf("%d",clock());
	return 0;
} 
