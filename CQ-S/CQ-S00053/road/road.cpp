//最小生成树 
//666
//这道题似乎有点难，让我思考一下 

//OI难
//[唐] QGY 
//键盘电脑六十张，整个机房值万钱。
//停码投笔不能思，拔伞四顾心茫然。
//欲做T2难入天，将码T3没时间。
//闲来去到厕所边，忽复敲码梦暑假。 
//OI难，OI难，多骗分，今安在？
//长代破码弱的闲，直接开始玩电脑 

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
bool mobailsy[15];
int c[15],da[15][10010];
int I_am_liangluo_s_father[10010];
int cnt=0;
//int fir[100110],nex[100110],to[100110],val[100110];
struct node{
	int u,v;
	long long w;
}a[2000010],b[2000010];
int find(int x){
	if(x!=I_am_liangluo_s_father[x])return I_am_liangluo_s_father[x]=find(I_am_liangluo_s_father[x]);
	return x;
}
bool cmp(node o,node w){
	return o.w<w.w;
}
//void add(int u,int v,int w){
//	cnt++;
//	nex[cnt]=fir[u]; 
//	fir[u]=cnt;
//	to[cnt]=v;
//	val[cnt]=w;
//}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
void liangluoll(){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int s=find(a[i].u),bb=find(a[i].v);
		if(s==bb)continue;
		I_am_liangluo_s_father[s]=bb;
		ans+=a[i].w;
	}
} 
void liangluolll(){
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		int s=find(a[i].u),bb=find(a[i].v);
		if(s==bb)continue;
		I_am_liangluo_s_father[s]=bb;
		ans+=a[i].w;
	}
} 
long long liangluollll(){
	long long sum=0;
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		int s=find(b[i].u),bb=find(b[i].v);
		if(s==bb)continue;
		I_am_liangluo_s_father[s]=bb;
		sum+=b[i].w;
	}
	return sum;
} 
void dfs(int kkksc03,long long now){
	if(kkksc03>k){
		memcpy(b,a,sizeof a);
		int t=cnt;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				++cnt;
				b[cnt].u=i;
				b[cnt].v=j;
				b[cnt].w=LONG_LONG_MAX;
				int flag=0;
				for(int quan=1;quan<=k;++quan){
					if(mobailsy[quan]){
						b[cnt].w=min(b[cnt].w,(long long)(da[quan][i]+da[quan][j]));
						flag=1;
					}
				}
				if(!flag)--cnt;
			}
		}
		long long dddd=liangluollll();
//		cout<<dddd<<endl;
		ans=min(ans,dddd+now);
//	cout<<endl<<cnt;
		cnt=t;
		for(int i=1;i<=n;++i){
			I_am_liangluo_s_father[i]=i;
		}
		return ;
	}
	mobailsy[kkksc03]=1;
	dfs(kkksc03+1,now+c[kkksc03]);
	mobailsy[kkksc03]=0;
	dfs(kkksc03+1,now);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++){
		I_am_liangluo_s_father[i]=i;
	}
	for(int i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
		cnt++;
//		add(a[i].u,a[i].v,a[i].w);
	}
	if(k==0){
		liangluoll(); 
		printf("%lld",ans);
		return 0;
	}
	int pfflag=0;
	for(int i=1;i<=k;++i){
		c[i]=read();
		if(c[i])pfflag=1;
		for(int j=1;j<=n;++j){
			da[i][j]=read();
		}
	}
	if(!pfflag){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				++cnt;
				a[cnt].u=i;
				a[cnt].v=j;
				a[cnt].w=LONG_LONG_MAX;
				for(int kkksc03=1;kkksc03<=k;++kkksc03){
//					add(i,j,da[kkksc03][i]+da[kkksc03][j]);
					a[cnt].w=min(a[cnt].w,(long long)(da[kkksc03][i]+da[kkksc03][j]));
				}
			}
		}
		liangluolll();
		printf("%lld",ans);
		return 0;
	}
	ans=LONG_LONG_MAX;
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
