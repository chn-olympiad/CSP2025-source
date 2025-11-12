#include <bits/stdc++.h>
using namespace std;
string s;

int number1(char aa)
{
	if (aa == '0') return 0;
	else if (aa == '1') return 1;
	else if (aa == '2') return 2;
	else if (aa == '3') return 3;
	else if (aa == '4') return 4;
	else if (aa == '5') return 5;
	else if (aa == '6') return 6;
	else if (aa == '7') return 7;
	else if (aa == '8') return 8;
	else  return 9;
}
struct Node
{
	int num,sum;
}a[15];

bool cmp(Node x,Node y)
{
	return x.num > y.num;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	for(char i:s)
	{
		if ('0' <= i && i <= '9')
		{
			int a1 = number1(i);
			a[a1].num = a1;
			a[a1].sum++;
		}
	}
	
	sort(a+1,a+11,cmp);
	
	int ans=0;
	for (int i = 0;i <= 9;i++)
	{
		if (a[i].sum != 0)
		{
			for (int j = 1;j <= a[i].sum;j++)
			{
				ans = ans*10 + a[i].num;
			}
		}
	}
	
	cout << ans;
	return 0;
}
