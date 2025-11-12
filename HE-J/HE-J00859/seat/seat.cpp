#include<bits/stdc++.h>
using namespace std;
//声明两个变量用来存储小明座位
long long l = 0,h = 1; 
//声明
long long n,m,a[105];
//声明一个绑定小明成绩的变量
long long b = 1; 
//创建一个函数，用来排序然后算座位
void px()
{
	//排序
	for(int i = 1; i < n*m; i ++)
	{
		for(int j = i + 1; j <= n*m; j ++)
		{
			if(a[i] < a[j])
			{
				//跟随 
				if(b == i)
				{
					b = j; 
				}
				else if(b == j)
				{
					b = i;
				}
				swap(a[i],a[j]);
			}
		}
	}
	//查找小明的座位
	//因为座位是n*m
	//所以n个为一组的去找
	l = b / n;
	//算出剩余不足的b
	if(b % n != 0)
	{
		l += 1;
		b -= l*n;
	}
	//小明和其它b-1个在一组
	//行数不就等于剩下的
	//记得判断该从上往下，还是从下往上
	if(l % 2 == 0)
	{
		h = m - b + 1;
	}
	else
	{
		h = b;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//输入
	cin >> n >> m;
	//输入成绩
	for(int i = 1; i <= n*m; i ++)
	{
		if(i == 1)
		{
			b = i;
		}
		cin >> a[i];
	}
	//用函数算出座位 
	px();
	//输出
	cout << l << ' ' << h; 
	return 0;
	//解注释 
}
