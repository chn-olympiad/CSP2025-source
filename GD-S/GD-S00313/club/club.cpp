#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5],sum[5],ans,n;
vector<int>l;
inline void solve(){
	scanf("%d",&n);
	ans=0,l.clear();
	for(int i=1;i<=3;i++)sum[i]=0;
	for(int i=1;i<=n;i++){
		int ma=0,t2=0;
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>ma)
				ma=a[i][j],t2=j;
		}
		for(int j=1;j<=3;j++)a[i][j]-=ma;
		ans+=ma,sum[t2]++;
	}
	int t=0,u=0;
	for(int i=1;i<=3;i++)if(sum[i]>u)u=sum[i],t=i;
	if(sum[t]<=n/2)return printf("%d\n",ans),void(0); 
	int p=sum[t]-n/2;
	//t社团最强,t社团要踢走p个人,l为所有人割爱的贡献最小 
	for(int i=1;i<=n;i++){
		int ma=-INT_MAX;
		if(a[i][t]!=0)continue;
		for(int j=1;j<=3;j++)if(j!=t)ma=max(ma,a[i][j]);
		l.push_back(ma);
	}
	sort(l.begin(),l.end());
	reverse(l.begin(),l.end());
	for(int i=0;i<p;i++)ans+=l[i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}
/*
我要夺回属于我的一切
好吧连最小生成树都打不出来了
好吧我kmp忘了 
Why would I ever
Why would I ever 					   *
Why would I ever think of leaving you  *
****************************************
吃吃吃吃吃士力架
吃吃吃次吃吃吃吃吃
睡睡睡睡觉
嘟嘟嘟嘟嘟
啦啦啦啦啦啦啦啦 
curry curry cu curry
哒哒哒哒哒哒

不骗分不骗分不骗分不骗分 
咚咚咚 

结束结束结束
顶顶顶顶顶顶顶顶顶顶顶
退役退役




				CSP-J/S2025第二轮-提高级(S组)
		 				准考证 
		 				
组别		CSP-S 
省份		广东省 
准考证号	GD-S00313
测试时间	2025年11月1日14:30-18:30 
认证语言		c++
姓名		 jty&hjl&czh&zzy&zzy&dadada 
性别		男
证件号		11451454188
学校		中山市华辰实验中学 
考场		中山市中山纪念中学 
座位号		考场114514(旧科学馆54188机房）座位号888 
提醒:为避免考场及座位号信息有变动，请务必于10月31日18:00以后再次登
录系统确认 
*/
