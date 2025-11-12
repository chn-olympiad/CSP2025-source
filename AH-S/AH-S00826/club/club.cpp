/*
2:05pm 
	五年了第一次写游记喵……不是现在限制年龄了吗怎么还这么多小学生
	哎CCF典型的圈钱思维，安卓CCF
	服了一年不碰这玩意水平要不敌初三了，我超文化课怎么这么坏啊
	真要坠机了，sublime怎么用来着
2:10pm
	怎么还有这么久才开始
	为什么不能带作业进考场，一想到一会结束晚上还要赤传奇瀚海牢逝xgz的数学卷子的石我就想笑
	CCF捅死你喵捅死你喵捅死你喵捅死你喵捅死你喵捅死你喵捅死你喵
2:14pm
	此时此景我不是要开始写神秘追忆小作文了……怎么还有这么就
	//freopen feropen 钓鱼这一块
	不对今年是不是不公示代码，坏了我成小丑了
2:20pm
	熟悉的神秘小广播又来了……五年了（其实指考了四次，2022年AH初中没考）怎么感觉还没人家一个暑假进步的快
	难蚌、传奇zly默歌词被嘲讽了，正义史官这一块
2:30pm
	“人杰地灵” 百年名校这一块
2:50pm
	T1硬模拟感觉有点倒闭阿
3:26(或者28？近视看不见钟）pm
	搓了1h的沟使完美的每个样例只错一组，你*了个*
3:37pm
	CCF神秘数据发力了，史山代码跑过5没跑过4
	这B数据我要你有什么用，一堆bug都能跑掉四个样子，你******
	不管了部分分有了，先开下一题
3:48pm
	倒闭了T2T3好像都不会
4：25pm
	**我在干什么 最小生成树写了个SPFA
5:15pm
	沟槽的CCF T4给的部分分还挺多
	小学生发力了
6：00pm
	标准结局：小孩哥被快捷键丹砂
	我超怎么感觉要毁了这次
*/
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;register char ch=getchar_unlocked();
	while(ch<'0'||'9'<ch){if(ch=='-') f=-f; ch=getchar_unlocked();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar_unlocked();}
	return x*f;
}
const int N=1e5+5;
int a[N],b[N],c[N];
bool flag[N];
struct node{
	int ex,it,id;
}sta[N];
inline int find(int i){
	if(a[i]>=b[i]&&a[i]>=c[i]) return 1;
	if(b[i]>=a[i]&&b[i]>=c[i]) return 2;
	return 3;
}
inline int findd(int i){
	if((b[i]>=a[i]&&a[i]>=c[i])||(b[i]<=a[i]&&a[i]<=c[i])) return 1;
	if((a[i]>=b[i]&&b[i]>=c[i])||(a[i]<=b[i]&&b[i]<=c[i])) return 2;
	return 3;
}
inline bool cmp(node x,node y){
	return x.ex<y.ex;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	register int T=read();
	while(T--){
		register int n=read(),i,tot1=0,tot2=0,tot3=0,ls=0;
		register long long ans=0;
		memset(flag,0,sizeof flag);
		for(i=1;i<=n;++i){
			a[i]=read(),b[i]=read(),c[i]=read();
			if(find(i)==1) ans+=a[i],++tot1;
			if(find(i)==2) ans+=b[i],++tot2;
			if(find(i)==3) ans+=c[i],++tot3;
		}
		if(tot1<=n/2&&tot2<=n/2&&tot3<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		if(tot1>n/2){
			ls=0;
			for(i=1;i<=n;++i){
				if(find(i)!=1) continue;
				if(findd(i)==2) sta[++ls].ex=a[i]-b[i],sta[ls].it=2,sta[ls].id=i;
				else sta[++ls].ex=a[i]-c[i],sta[ls].it=3,sta[ls].id=i;
			}
			sort(sta+1,sta+1+tot1,cmp);
			for(i=1;tot1>=(n/2+i);++i){
				ans-=sta[i].ex;
				if(sta[i].it==2) ++tot2,flag[sta[i].id]=1;
				else ++tot3,flag[sta[i].id]=1;
			}
			if(tot2>n/2){
				ls=0;
				for(i=1;i<=n;++i){
					if(find(i)!=2&&!flag[i]) continue;
					sta[++ls].ex=b[i]-c[i];
				}
				sort(sta+1,sta+1+tot2,cmp);
				for(i=1;tot2>=(n/2+i)||sta[i].ex<0;++i) ans-=sta[i].ex;
			}
			if(tot3>n/2){
				ls=0;
				for(i=1;i<=n;++i){
					if(find(i)!=3&&!flag[i]) continue;
					sta[++ls].ex=c[i]-b[i];
				}
				sort(sta+1,sta+1+tot3,cmp);
				for(i=1;tot3>=(n/2+i)||sta[i].ex<0;++i) ans-=sta[i].ex;
			}
			printf("%lld\n",ans);
		}
		else if(tot2>n/2){
			ls=0;
			for(i=1;i<=n;++i){
				if(find(i)!=2) continue;
				if(findd(i)==1) sta[++ls].ex=b[i]-a[i],sta[ls].it=1,sta[ls].id=i;
				else sta[++ls].ex=b[i]-c[i],sta[ls].it=3,sta[ls].id=i;
			}
			sort(sta+1,sta+1+tot2,cmp);
			for(i=1;tot2>=(n/2+i);++i){
				ans-=sta[i].ex;
				if(sta[i].it==1) ++tot1,flag[sta[i].id]=1;
				else ++tot3,flag[sta[i].id]=1;
			}
			if(tot1>n/2){
				ls=0;
				for(i=1;i<=n;++i){
					if(find(i)!=1&&!flag[i]) continue;
					sta[++ls].ex=a[i]-c[i];
				}
				sort(sta+1,sta+1+tot1,cmp);
				for(i=1;tot1>=(n/2+i)||sta[i].ex<0;++i) ans-=sta[i].ex;
			}
			if(tot3>n/2){
				ls=0;
				for(i=1;i<=n;++i){
					if(find(i)!=3&&!flag[i]) continue;
					sta[++ls].ex=c[i]-a[i];
				}
				sort(sta+1,sta+1+tot3,cmp);
				for(i=1;tot3>=(n/2+i)||sta[i].ex<0;++i) ans-=sta[i].ex;
			}
			printf("%lld\n",ans);
		}
		else{
			ls=0;
			for(i=1;i<=n;++i){
				if(find(i)!=3) continue;
				if(findd(i)==1) sta[++ls].ex=c[i]-a[i],sta[ls].it=1,sta[ls].id=i;
				else sta[++ls].ex=c[i]-b[i],sta[ls].it=2,sta[ls].id=i;
			}
			sort(sta+1,sta+1+tot3,cmp);
			for(i=1;tot3>=(n/2+i);++i){
				ans-=sta[i].ex;
				if(sta[i].it==2) ++tot2,flag[sta[i].id]=1;
				else ++tot1,flag[sta[i].id]=1;
			}
			if(tot2>n/2){
				ls=0;
				for(i=1;i<=n;++i){
					if(find(i)!=2&&!flag[i]) continue;
					sta[++ls].ex=b[i]-a[i];
				}
				sort(sta+1,sta+1+tot2,cmp);
				for(i=1;tot2>=(n/2+i)||sta[i].ex<0;++i) ans-=sta[i].ex;
			}
			if(tot1>n/2){
				ls=0;
				for(i=1;i<=n;++i){
					if(find(i)!=1&&!flag[i]) continue;
					sta[++ls].ex=a[i]-b[i];
					}
				sort(sta+1,sta+1+tot1,cmp);
				for(i=1;tot1>=(n/2+i)||sta[i].ex<0;++i) ans-=sta[i].ex;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
