#include<bits/stdc++.h>
using namespace std;
int a,b,r;
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> a >> b;
	int s[a * b];
	for (int i = 0;i < a * b;i++)
	{
		cin >> s[i];
		if (i == 0)
		{
			r = s[i];
		}
	}
	int big_s[a * b],max_chengji = 0,max_bianhao;
	//判断最大值
	for (int i = 0;i < a * b;i++)
	{
		for (int j = 0;j < a * b;j++)
		{
			if (max_chengji <= s[j])
			{
				max_chengji = s[j];//max成绩存储本次最大成绩
				max_bianhao = j;//max编号存储本次移除的成绩在列表中的编号
			}
		}
		s[max_bianhao] = 0;
		big_s[i] = max_chengji;
		max_chengji = 0;
	}
	for(int v = 0;v < a*b;v++)
	{
		if (big_s[v] == r)
		{
			r = v;
		}
	}
	int n[a * b + 5],m[a * b + 5];
	n[0] = 1;
	m[0] = 1;
	for (int i = 1;i < a * b;i++)
	{
		if (m[i - 1] % 2 == 1)//奇数列需增加
			if (n[i - 1] + 1 > b)
			{
				m[i] = m[i - 1] + 1;
				n[i] = b;//新的一行从底开始
			}
			else
			{
				m[i] = m[i - 1];
				n[i] = n[i - 1] + 1;//正常情况下需加1
			}
		else//否则为偶数列
		{
			if (n[i - 1] - 1 < 1)
			{
				m[i] = m[i - 1] + 1;
				n[i] = 1;//新的一行从头开始
			}
			else
			{
				n[i] = n[i - 1] - 1;//正常情况下需减1
				m[i] = m[i - 1];
			}
		}
	}
	for (int i = 0;i < 4;i++)
	{
		cout << m[i] << " " << n[i] << endl;
	}
	cout << r << endl;
	cout << m[r] << " " << n[r] << endl;
	return 0;
}

