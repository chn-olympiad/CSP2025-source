#include<bits/stdc++.h>
using namespace std;
int n,a[1145*5];
int ans=0;
const int mod=998244353;
void dfs(int i,int used,int sum,int mx,bool flg)
{
	if(sum>mx*2&&used>=3&&flg) ans=(ans+1)%mod;
	if(i>n) return;
	dfs(i+1,used,sum,mx,0);
	dfs(i+1,used+1,sum+a[i],max(mx,a[i]),1);
}
int quickpow(int a,int b)
{
	int res=1;
	while(b>0) res=res*a%mod,b--;
	return res%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int mmx=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mmx=max(mmx,a[i]);
	if(mmx==1) {cout<<quickpow(2,n)-n-(n*(n-1)%mod/2)-1;return 0;}
	dfs(1,0,0,0,1);
	cout<<ans%mod;
	return 0;
}
//rp++;
/*
	写点东西吧，感觉要 AFO 了
	希望看到的人能把它看完 
	拜谢，祝rp++;（为什么每次 polygon 都能打成 polugon 啊） 
	
	本人坐标福建厦门，洛谷uid 973540
	从什么时候开始学 OI 的？好像是六年级吧
	那时候还是在学 FMSLogo，就因为一次出去比赛拿了全市第二被招进 XMYZ 的 OI 班了，于是从 FMSLogo 和 Python 转向 C++
	感觉 C++ 和 Python 还是不太一样
	
	因此，我的生活因为 C++ 改变了许多
	以前周末都能和同学一起出去玩，现在每周六下午都要从海沧跑来 YZ 上课，回去还要写作业
	以前拿电脑都是玩游戏，现在拿电脑都是写题
	可以说，我的生活被 reset 了
	
	而且，认识她，喜欢上她也是从学 OI 开始的
	那时候，我在本校的 OI 集训队里面，她也在
	六年级分班，我和她分到了一起 
	于是吧两个人就认识了
	从分班那一天起我们就变得无话不谈 
	后来她不学 OI 了，转 whk 了，我们的交谈也就越来越少 
	 
	毕业那天，我跟她表白了
	于是她笑了笑，至今不知道何意味 
	
	到了初中，学业压力一起堆上来，况且我们学校还是厦门岛外最卷的学校 
	留给 OI 的时间越来越少 
	初一那年，第一次参加 CSP，获得了 J 245，S 120 的“优异”成绩：几乎被全机房吊打 
	今年的我已经初二了，这次再不拿一个 1= 回家就要 AFO 了 （感觉真TM要 AFO 了，T3+T4<100，等掉） 
	AFO 以后干什么呢？转 whk~~找我 npy 去~~备战中考呗 
	到了高中，时间可能会多一点吧
	
	希望这次能拿一个 1= 回家（那最好了） 
	希望以后走中考回到 XMYZ 能重回 OI 
	感谢所有人两年来的支持。 
	谢谢我的教练，谢谢我的家人
	谢谢你，myx。 
*/
