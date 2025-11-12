#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000001],cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}
//广东省广州大学附属中学大学城校区游记
//我是广州大学 附属中学黄华路校区的，来高级的大学城考试！
//发现考场就是我之前信息夏令营集训的机房…… 
//8:26 发现两台电脑之间隔得好近又没有隔板，以为又要有一堆人作弊了，又发现CCF给每一台电脑都贴了一层好高级的防偷窥黑膜，旁边人的电脑都是黑色的啥都看不见，好高级 
//8:35 折腾了好久终于把题目文件解压出来了。
//8:36 T1超级送分题 
//8:40 T1 AC,看T2，非常简单，我用的是dfs+map<pair<int,int>,int> 
//9:03 忽然说checker用不了了，CCF你不要搞人家心态啊 
//9:11 T2 过样例 
//9:12 看T3时忽然想到是不是T1T2没加return 0;发现真没有赶紧补上 ,顺便把ios加上了 
//9:30 T3还是不太会，目前思路是O(n^2):前缀和然后枚举每一个起点和终点+一个B性质=65pts
//9:37 想到T3对于性质C可以使用dp[i][j],i存下标，j存当前区间异或和为多少->80pts ,看T4 
//9:57 T4是一个方案dp，想到可以dp[i][j][k]，分别表示下标，最大值，和，用一个三重循环，第一维可以压掉，可以拿到80pts 
//10:00 写T3,时间有点赶 
//10:03 从T4得到启发T3也可以压维，貌似100pts
//10:08 好吧貌似复杂度起飞->80pts 
//10:30 ok dp不可做->65pts; 
//10:57 狂写62行T3 得到65pts
//11:06 好像貌似有人用cmd不知道干嘛，把CCF的人都叫过来了（不要管，专心写） 
//11:29 我还是不太会写dp啊，改策略：拿到1~10和15~20的分（64pts） 
//11:52 写完T4,坐等收卷 
