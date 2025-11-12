#include <bits/stdc++.h>
using namespace std;

int a[150];
int b[15][15];
priority_queue<int>q;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int value = 0;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		q.push(a[i]);
	}
	value = a[1];//小r的成绩
	int pos_i = 0;
	int pos_j = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			int temp = q.top();
			q.pop();
			b[j][i] = temp;
			if(temp == value)
			{
				pos_i = i;
				pos_j = j;
			}
		}
	} 
	
	if(pos_i%2 == 0)//偶数列，由下到上
	{
		cout << pos_i << " " << n-pos_j+1;
	}
	else//奇数列，由上到下
	{
		cout << pos_i << " " << pos_j;
	}
	return 0;
}