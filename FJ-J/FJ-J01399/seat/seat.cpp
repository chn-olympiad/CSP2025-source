#include <bits/stdc++.h>
using namespace std;

int w=1;
int ga;

int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//freopen
	
	int n,m;
	cin >> n >> m;
	cin >> ga;
	//input
	
	for(int i=1; i<n*m; i++)
	{
		int t;
		cin >> t;
		if(t>ga) w++;
	}
	//count rank
	
	//	cout << w << endl;
	
	int x,y;
	if(w%n==0)
	{
		x=w/n;
	}
	else
	{
		x=w/n+1;
	}
	if(w%n==0)
	{
		if(x%2==1)
		{
			y=n;
		}
		else
		{
			y=1;
		}
	}
	else
	{
		if(x%2==1)
		{
			y=w%n;
		}
		else
		{
			y=n-(w%n)+1;
		}
	}
	//count line and row

	cout << x << ' ' << y;
	//output
	
	return 0;
	//ending
}

// 本程序思路简单 甚至做到了除输入外的 O(1)算法
// 首先统计小 R 的相对位次
// 显然你的位次与实际成绩无关
// 通过简单的数学就可以看出上述代码

// 9：43 
// 破防了
// 上面的话都是 hack 之前的
// 自己写了 hack 死活过不去
// 摆了 

// 10:03
// 自己写的 hack 过了 
// 还是感觉要完蛋
 

