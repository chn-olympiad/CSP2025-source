#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,q,ip[N],wxy,yxw;
string s[N][3],t1,t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		int l=s[i][1].size();
		for(int j=1;j<=l;j++)
		{
			if(s[i][1][j-1]=='b')wxy=j;
			if(s[i][2][j-1]=='b')yxw=j;
			
		}ip[wxy-yxw+1000005]++;
	}
	while(q--)
	{
			cin>>t1>>t2;
			int l=t1.size();
			for(int j=1;j<=l;j++)
			{
				if(t1[j]=='b')wxy=j;
				if(t2[j]=='b')yxw=j;
			}
			cout<<ip[wxy-yxw+1000005]<<endl;
	}
	return 0;
}
//2025.11.1 17:08:40 finish this code
//燃尽了真的
//T4除了看得懂题面就没有会的了 
/*
这应该是我最后一次信息学竞赛了
5年前接触图形化
3年前学C++
但如今，我只觉得信息学竞赛这条路越来越不契合我了
数学反倒成为我最引以为傲的优势
高端一点的算法，翻来覆去还是不懂 
可能，从一开始，我就不适合学编程吧 

在学校，同学们都说我是理科的大佬，可在更多的时候，我到感觉自己是个平庸的不能再平庸的人了
数学总有那么几道绞尽脑汁也行不到的压轴题，物理也总是粗心大意，更别提化学了，它的选择题就是我的滑铁卢
还有好多好多.......

但，不论过去怎么样，只希望未来的我能发挥出光和热
至少，在自己的世界里，熠熠生辉



献给未来那个被生活打压的我 
*/ 
