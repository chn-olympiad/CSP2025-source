#include<bits/stdc++.h>
using namespace std;
//声明一个数组用来存储数 和 排序数,输入用的字符串 
long long a[1000005];
char b[1000005];
int ans = 0,k;
//定义一个函数,用来查找数
void cz()
{
	int j = 0;
	for(int i = 0; i < k; i ++)
	{
		if(b[i] >= '0' && b[i] <= '9')
		{
			//化为整形加入
			a[j] = b[i] - '0';
			//算出有几个数字
			ans ++;
			j ++;
		} 
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//输入
	cin >> b;
	k = strlen(b);
	//找出数
	cz();
	//排序
	for(int i = 0; i < ans-1; i ++)
	{
		for(int j = i + 1; j < ans; j ++)
		{
			if(a[i] < a[j])
			{
				swap(a[i],a[j]);
			} 
		}
	}
	for(int i = 0; i < ans; i ++)
	{
		cout << a[i];
	}
	return 0;
	//解注释 
}
