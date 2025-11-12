#include<bits/stdc++.h>
using namespace std;
int mxx(int a,int b,int c)
{
	return max(max(a,b),c);
}
struct stu
{
	int a[3];
	bool operator<(stu b)
	{
		return mxx(a[0],a[1],a[2])>mxx(b.a[0],b.a[1],b.a[2]);
	}
};
int n,sum=0,ans=0;
vector<stu> v;
int f[3];
void dfs(int x)
{
	if(x==n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(f[i]<n/2)
		{
			f[i]++;
			sum+=v[x].a[i];
			dfs(x+1);
			sum-=v[x].a[i];
			f[i]--;
		}
	}
	return;
}
void solve()
{
	cin>>n;
	v.resize(n);
	for(auto& i:v)
		cin>>i.a[0]>>i.a[1]>>i.a[2];
	if(n<=18)
	{
		dfs(0);
		cout<<ans<<endl;
		v.clear();
		sum=ans=f[0]=f[1]=f[2]=0;
		return;
	}
	sort(v.begin(),v.end());
	int ans_=0,f_[3]={};
	for(int i=0;i<n;i++)
	{
		int maxx=-1,maxj;
		for(int j=0;j<3;j++)
		{
			if(v[i].a[j]>maxx&&f_[j]<n/2)
			{
				maxx=v[i].a[j];
				maxj=j;
			}
		}
		ans_+=maxx;
		f_[maxj]++;
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
/*
 * 初三了，打完这场CSP就去备考了。要是考不上有OI训练营的高中就真的AFO了……
 * 估分35pts，这题大概是DP但我不会写（悲
 * 求进迷惑行为大赏
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 我是温迪的狗！！！
 * 
 * 《风与飞鸟》
 * 传说那阳光
 * 沐浴万物生长
 * 而我抬头
 * 风沙万丈
 * 
 * 在那背后
 * 是怎样的蓝天
 * 一墙之隔
 * 一生之所向
 * 
 * 陌生的精灵
 * 听到这琴声吗
 * 随我歌唱
 * 带我远洋
 * 
 * 再小的希望
 * 能像花一样尽情绽放
 * 迎接朝阳
 * 
 * 不安的音符跳动着
 * 在心中鸣响乐章
 * 没有人能困住灵魂
 * 站起身伸出翅膀
 * 
 * （这段忘了）
 * 
 * 顷刻间意志
 * 如同熊熊烈火
 * 看它燎原
 * 肆意盘旋
 * 
 * 迷途的人们
 * 别再遮蔽双眼
 * 迎向逆风
 * 怒视深渊
 * 
 * 随着我自由地高歌
 * 回荡在塔顶漩涡
 * 在王座崩落的一刻
 * 我看见天的颜色
 * 
 * ……后面忘了
 * （666高潮部分全忘了，记性真好）
 * ……前面忘了
 * 
 * 传说那阳光
 * 沐浴万物生长
 * 风与飞鸟
 * 自由飞翔
 * 
 * Luogu UID:819326
 * 2025/11/01
*/
