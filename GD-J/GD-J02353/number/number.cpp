#include<bits/stdc++.h>
using namespace std;
string st; 
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>st;
	for(long long i=0;i<st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			a[st[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=0;j<a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
//8:40 创建文件。 
//8:50 做完，难度红，预计 100pts 
//11:55 做完，预计 100+100+60+100=360 
//------------题外话分界线------------------
//望不要在迷惑行为大赏里看到我... 
/* 

CSP快到了，提前祝你考试顺利！接龙哈！发给你最好的10个朋友，超过15
个就锦鲤保佑你，今天必须发完，想起谁，发给谁，包括我 
 传送0人 CSP忘写feropen
 传送1人 feropen打错
 传送5人 不可以总司令骗分大神
 传送10人 卡常卡过第四题
 传送15人 AK CSP！
 发给我 CSP爆0
别问，问就是让你转发

赛前这种私信炸我铃... 
顺带一提，我传送了0人，但如你所见，我还是打了feropen 
贺以为！

GD-J 0235 3
考号中的神秘四位数 

考场空调冷死我力
不玩了，做T3了 

You have no egg!
我是糊涂人，你是精明人 
*/
