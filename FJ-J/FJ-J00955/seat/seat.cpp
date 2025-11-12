/*
？请输入文本
n和m好大
请输入文本
孩子们我是推式子题
CCF我们真爱你口牙 

10:33不是这个东西真的有必要对拍吗
不对这是连暴力都没得打的题
欸我有一计我推一下O(1)式子看看能不能过
简单推了一下发现第x个数的坐标是(\lfloor\frac{x}{n+1}\rfloor+[(n+1)|x],x%(n+1)-[(n+1)|x]) 
ok小样例炸了
哦是向上取整
还少了一个非和减法 和其他东西
ok小样例过了 
ok第三个炸了
算了好复杂，还要分类讨论，不写了
反正是可以O(n)的 
*/ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<pair<int,int>>q;
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int a;
		cin>>a;
		q.push(make_pair(a,i));
	}
	int x=1,y=1,fl=1;
	while(q.size())
	{
		pair<int,int> u=q.top();
//		cout<<u.first<<' '<<u.second<<' '<<x<<' '<<y<<'\n'; 
		q.pop();
		if(u.second==1)
		{
			cout<<x<<' '<<y;
			break;
		}
		y+=fl;
		if(y<1||y>n)
		{
			x++;
			fl=((fl==1)?-1:1);
			y+=fl;
		}
	}
}
