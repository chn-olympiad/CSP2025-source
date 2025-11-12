#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int val,id;
}a[100005],b[100005],c[100005];
int las[100005],lasid[100005];
bool vis[100005];
bool cmp(node a,node b){
	if(a.val!=b.val)return a.val>b.val;
	return a.id<b.id;
}
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*w;
}
/*
 //freopen("");
 zuowen 作文
  
	luogu 750120
	
	AFO力 
 
 中考加油！ 用CSP的rp换取中考的rp！！ 
 无缘CSPS 1=  
 怎么说呢
 JS组考的比去年还差
 J组今年大概200+
 S取[0,40]，连2=都拿不到
 我能怎么说呢
 J组后面两道是dp
 我的弱项
 
 S组第一道贪心，不会调了
 第二道 最小生成树
 把k条边融到原图，跑一边应该就过了
 有一点小细节
 可惜我没复习到
 第3道盲猜字符串哈希匹配
 第4道dp，还是不会
 
 J组 第一二道题 很简单 7分钟AC
 第34道全是dp，我吐了，但是应该1=
 
 相隔一年的时间
 经历了大大小小的集训，认识了形形色色的朋友
 不能说是没有收获吧
 起码成长了一些
 
 我曾为自己是天才 
 现在感觉自己是个傻子
 
 最后30分钟了
 能打的暴力都打了
 今天中午聂老师和任老师问我考的怎么样
 我都没好意思说
 
 哎
 要是我昨天晚上不玩就好了
 说不定就能看到这些知识点了呢
 
 人生没有回头路
 只能踏踏实实拿出120%的力气冲击中考
 
 我感觉我这是第一次遭受这么大的挫折
 集训拼了拼
 我现在回想起来
 感觉就其实没有用完全的努力
 
 我也不知道为什么
 学信息有一种深深的无力感
 我的智商正在退化
 看电脑看的（（不是））
 
 ccf你真是个大帅包 
  ccf你真是个大帅包 
   ccf你真是个大帅包 
    ccf你真是个大帅包 
     ccf你真是个大帅包 
      ccf你真是个大帅包 
       ccf你真是个大帅包 
        ccf你真是个大帅包 
         ccf你真是个大帅包 
ε=(′ο｀*)))唉
冲击中考吧

很难想象我出考场该怎么面对父母，老师

我已经尽力了 

吗？

感觉再也拿不出以前的感觉了
只能冲击中考了
（其实考好了也得冲

这条路算是走到悬崖了
只能回头追赶我的同学了

墙上写着
网络促进教育
学习点亮人生
做信息时代的终生学习者

ccf J组1分钟检查一个人，我真服了
浪费我30分钟
说不定就能看见最小生成树呢
我浪费了我人生中一段最宝贵的时间

毕导说过
若人存在记忆的时间是4-80岁
那在对数的世界中 人的中点就在
   ^^    ______
 //||	||    |/
   || 	------||
   ||	||	  |/ 
 ------ -------
 
 (18)岁
 
 我还是太过放纵自己了
 要是能在早学一年
 要是昨天不玩游戏
 要是我今天J组能早走45分钟
 要是我每天控制作息
 要是我不在那天课上睡1个小时
 要是我在1年内所有课上累计睡觉的20小时
 能被利用上 是不是不会有今天这般下场？
 
 没办法，命就是这样
 辜负了老师的信任
 辜负了父母的付出与陪伴 
 (中控机器出问题 8:46才开始，我18号检查了35分钟+)
 是不是今天就不会有这个后果了 
  
  纵观一生
  幼儿园我爷奶有关系没花钱
  小学数学好/关系没花钱
  获得YMO 数学英语A
  围棋 忘了() 反正不低
  为什么不小学中学高中一体啊 
  为什么不分班 
  为什么要学沟槽的文科 
  为什么要把青春的时间浪费给学习
  	--其实是应该学习 但是太卷了
	  学习压力 so large
	中国....小学生数学...竞赛全国第1-3 ?又忘了
	珠心算
	什么烂七八糟的
	
	啊啊啊啊啊啊啊啊啊啊啊啊啊
	我的脑子
	我的脑子怎么了
	怎么记忆力越来越差了
	
	语文为什么强制学byd课文
	为什么不分开学
	想上哪个上哪个 
   选理科 or 文科
   这样的话又节省时间
   有可以专精自己的突出点
   这样不好吗 
   搞不懂为什么安排成这样
   学习越来越功利
   md还有3分钟
   我*********的
   
   ccf CSP-JS 2025
   	 J [160,260]
	S [0,60]
	
	我是废物
	我是废物
	
	这有什么意义呢？ 
	
	Warning Electric shack
	中考 rp++
	__int128 zhongkao_rp=(1<<128)-1; 
	Minecraft yyds
	再见信息班同学！！！！！！ 
*/
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		int acn=0,bcn=0,ccn=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(las,0,sizeof(las));
		memset(vis,0,sizeof(vis));
		n=read();
		int nn=n;
		for(int i=1;i<=n;i++){
			a[i].val=read();
			b[i].val=read();
			c[i].val=read();
			a[i].id=i,b[i].id=i,c[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n&&nn>0;i++){
			bool AA=0,BB=0,CC=0;
			int ca,cb,cc;
			ca=a[i].id;cb=b[i].id;cc=c[i].id;
			if(vis[ca]){
				if(las[ca]>=a[i].val){
					AA=1;
				}
				else{
					if(lasid[ca]==2)bcn--;
					if(lasid[ca]==3)ccn--;
					acn++;
					lasid[ca]=1;
					las[ca]=a[i].val;
				}
			}
			if(vis[cb]){
				if(las[cb]>=b[i].val)BB=1;
				else{
					if(lasid[cb]==1)acn--;
					if(lasid[cb]==3)ccn--;
					bcn++;
					las[cb]=b[i].val;
					lasid[cb]=2;
				}
			}
			if(vis[cc]){
				if(las[cc]>=c[i].val)CC=1;
				else{
					if(lasid[cc]==2)bcn--;
					if(lasid[cc]==1)acn--;
					ccn++;
					las[cc]=c[i].val;
					lasid[cc]=3;
				}
			}
			if(nn==1){
				if(a[i].val>b[i].val&&a[i].val>c[i].val){
					if(!AA&&acn<=n/2){
						vis[ca]=1;
						las[ca]=a[i].val;
						lasid[ca]=1;
						acn++;
						nn--;
					}
				}else if(b[i].val>c[i].val&&b[i].val>a[i].val){
					if(!BB&&bcn<=n/2){
						vis[cb]=1;
						las[cb]=b[i].val;
						lasid[cb]=2;
						bcn++;
						nn--;
					}
				}else if(a[i].val==b[i].val&&a[i].val>c[i].val){
					int fff=0;
					if(!AA&&acn<=n/2){
						vis[ca]=1;
						las[ca]=a[i].val;
						lasid[ca]=1;
						acn++;
						nn--;
						fff=1;
					}
					if(vis[cb]&&fff==0){
						if(las[cb]>=b[i].val)BB=1;
						else{
							if(lasid[cb]==1)acn--;
							if(lasid[cb]==3)ccn--;
							bcn++;
							las[cb]=b[i].val;
							lasid[cb]=2;
						}
					}
					if(!BB&&bcn<=n/2&fff==0){
						vis[cb]=1;
						las[cb]=b[i].val;
						lasid[cb]=2;
						bcn++;
						nn--;
					}
				}else if(a[i].val==c[i].val&&a[i].val>b[i].val){
					int fff=0;
					if(!AA&&acn<=n/2){
						vis[ca]=1;
						las[ca]=a[i].val;
						lasid[ca]=1;
						acn++;
						nn--;
						fff=1;
					}
					if(vis[cc]&&fff==0){
						if(las[cc]>=c[i].val)CC=1;
						else{
							if(lasid[cc]==2)bcn--;
							if(lasid[cc]==1)acn--;
							ccn++;
							las[cc]=c[i].val;
							lasid[cc]=3;
						}
					}
					if(!CC&&ccn<=n/2&&fff==0){
						vis[cc]=1;
						las[cc]=c[i].val;
						lasid[cc]=3;
						ccn++;
						nn--;
					}
				}else if(b[i].val==c[i].val&&a[i].val>a[i].val){
					int fff=0;
					if(!BB&&bcn<=n/2){
						vis[cb]=1;
						las[cb]=b[i].val;
						lasid[cb]=2;
						bcn++;
						nn--;
						fff=1;
					}
					if(vis[cc]&&fff==0){
						if(las[cc]>=c[i].val)CC=1;
						else{
							if(lasid[cc]==2)bcn--;
							if(lasid[cc]==1)acn--;
							ccn++;
							las[cc]=c[i].val;
							lasid[cc]=3;
						}
					}
					if(!CC&&ccn<=n/2&&fff==0){
						vis[cc]=1;
						las[cc]=c[i].val;
						lasid[cc]=3;
						ccn++;
						nn--;
					}
				}else{
					if(!CC&&ccn<=n/2){
						vis[cc]=1;
						las[cc]=c[i].val;
						lasid[cc]=3;
						ccn++;
						nn--;
					}
				}
				
			}else if(nn==2){
				if(a[i].val<b[i].val&&a[i].val<c[i].val){
					if(!BB&&bcn<=n/2){
						vis[cb]=1;
						las[cb]=b[i].val;
						lasid[cb]=2;
						bcn++;
						nn--;
					}
					if(vis[cc]){
						if(las[cc]>=c[i].val)CC=1;
						else{
							if(lasid[cc]==2)bcn--;
							if(lasid[cc]==1)acn--;
							ccn++;
							las[cc]=c[i].val;
							lasid[cc]=3;
						}
					}
					if(!CC&&ccn<=n/2){
						vis[cc]=1;
						las[cc]=c[i].val;
						lasid[cc]=3;
						ccn++;
						nn--;
					}
				}else if(b[i].val<a[i].val&&b[i].val<c[i].val){
					if(!AA&&acn<=n/2){
						vis[ca]=1;
						las[ca]=a[i].val;
						lasid[ca]=1;
						acn++;
						nn--;
					}
					if(vis[cc]){
						if(las[cc]>=c[i].val)CC=1;
						else{
							if(lasid[cc]==2)bcn--;
							if(lasid[cc]==1)acn--;
							ccn++;
							las[cc]=c[i].val;
							lasid[cc]=3;
						}
					}
					if(!CC&&ccn<=n/2){
						vis[cc]=1;
						las[cc]=c[i].val;
						lasid[cc]=3;
						ccn++;
						nn--;
					}
				}else{
					if(!AA&&acn<=n/2){
						vis[ca]=1;
						las[ca]=a[i].val;
						lasid[ca]=1;
						acn++;
						nn--;
					}
					if(vis[cb]){
						if(las[cb]>=b[i].val)BB=1;
						else{
							if(lasid[cb]==1)acn--;
							if(lasid[cb]==3)ccn--;
							bcn++;
							las[cb]=b[i].val;
							lasid[cb]=2;
						}
					}
					if(!BB&&bcn<=n/2){
						vis[cb]=1;
						las[cb]=b[i].val;
						lasid[cb]=2;
						bcn++;
						nn--;
					}
				}
				
			}else{
				if(!AA&&acn<=n/2){
					vis[ca]=1;
					las[ca]=a[i].val;
					lasid[ca]=1;
					acn++;
					nn--;
				}
				if(!BB&&bcn<=n/2){
					vis[cb]=1;
					las[cb]=b[i].val;
					lasid[cb]=2;
					bcn++;
					nn--;
				}
				if(!CC&&ccn<=n/2){
					vis[cc]=1;
					las[cc]=c[i].val;
					lasid[cc]=3;
					ccn++;
					nn--;
				}
			}
			
			//printf("acn=%d bcn=%d ccn=%d nn=%d ",acn,bcn,ccn,nn);
			//cout<<AA<<BB<<CC<<'\n';
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=las[i];
			//cout<<las[i]<<" ";
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1 3 2 4 5 3 4 3 5 1
4
0 1 0 0 1 0 0 2 0 0 2 0
2
10 9 8 4 0 0 


*/

