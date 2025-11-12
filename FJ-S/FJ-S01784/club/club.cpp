#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int T,n,c1,c2,c3,t,t1,t2,t3,s,ss;
long long ans;
int vis[N];
struct Node{
	int w,id;
}d1[N],d2[N],d3[N];

bool cmp(Node a,Node b){
	return a.w>b.w;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans = 0;
		c1=1,c2=1,c3=1;
		s=0,ss=0;
		t=0,t1=0,t2=0,t3=0;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d1[i].w,&d2[i].w,&d3[i].w);
			int a1=d1[i].w,a2=d2[i].w,a3=d3[i].w;
			int mi=min(a1,min(a2,a3));
			int ma=max(a1,max(a2,a3));
			int q = a1+a2+a3-mi-ma;
			ans += q;
			d1[i].w = a1-q;
			d2[i].w = a2-q;
			d3[i].w = a3-q;
			d1[i].id = i;
			d2[i].id = i;
			d3[i].id = i;
		}
		sort(d1+1,d1+n+1,cmp);
		sort(d2+1,d2+n+1,cmp);
		sort(d3+1,d3+n+1,cmp);
		for(int i=1;i<=n;i++){
			while(vis[d1[c1].id]&&c1<=n+1) c1++;//ºöÂÔÒÑÊ¹ÓÃ 
			while(vis[d2[c2].id]&&c2<=n+1) c2++;
			while(vis[d3[c3].id]&&c3<=n+1) c3++;
			if(d1[c1].w>d2[c2].w){
				if(t1<n/2){
					s = d1[c1].w;
					ss= d1[c1].id;
					t = 1;
				}else{
					s = d2[c2].w;
					ss= d2[c2].id;
					t = 2;
				}
			}else{
				if(t2<n/2){
					s =d2[c2].w;
					ss= d2[c2].id;
					t = 2;
				}else{
					s = d1[c1].w;
					ss= d1[c1].id;
					t = 1;
				}
			}
			if(s>d3[c3].w){
				ans += s;
				vis[ss] = 1;
				if(t==1){
					t1++;
				}else{
					t2++;
				}
			}else{
				if(t3<n/2){
					ans += d3[c3].w;
					vis[d3[c3].id] = 1;
					t3++;
				}else{
					ans += s;
					vis[ss] = 1;
					if(t==1){
						t1++;
					}else{
						t2++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
}
