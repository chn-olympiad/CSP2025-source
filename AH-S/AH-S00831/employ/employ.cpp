#include<bits/stdc++.h>
using namespace std;
const long long pri=998244353;
int main()
{
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   int n,m,flag=1,p,cnt;
   string s;
   cin>>n>>m;
   cnt=n;
   cin>>s;
   for(int i=1;i<=n;i++)
   {
	   cin>>p;
	   if(!p)cnt--;
   }
   for(int i=0;i<n;i++)
   {
	   if(s[i]=='0')flag=0;
   }
   if(flag)
   { 
	    long long ans=1;
	   for(long long i=2;i<=cnt;i++)
	   {
		   ans=(ans*i)%pri;
	   }
	   cout<<ans;
   }
   return 0;
}

















/*1446 用16分钟读了题目
 * 1516 放弃T1转打T4送分点，T1到底如何搜索？
 * 1539 再次豪掷20分钟于T4发现思路又是错的
 * 1544 受不了了。1-4点打暴力吧
 * 1550 "bits.stdc++.h"(唐)
 * 1553 打完性质A。但不确认啊。。。
 * 1624 一个dfs打40分钟，浪费时间。。
 *      比赛近半程。
 * 1632 T1B有想法了
 * 1644 T1B打完
 * 1658 （拿10^5数据稍微测了一下）咱能拿50分么？？
 * 1704 完蛋最小生成树忘了怎么打了
 * 1708 那不对啊，为什么你1-4的n比性质还多(?)用一个半小时试试看？
 * 1710 我将确认放弃T4。并在T3全输出0。哎哎。
 * 1715 给T3作了个了结。希望能骗到个5分。剩下的时间全押T2。
 * 1727 厕所行，试试T1C？
 * 1758 T2的1-4可能是编完了吧。。
 * 1803 T2A没那么简单。剩下的时间肯定来不及了。T4还有m=1??试试看
 * 1806 布豪！！！
 * 1810 交了
 */
