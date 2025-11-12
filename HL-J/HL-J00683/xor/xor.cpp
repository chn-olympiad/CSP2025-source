#include <bits/stdc++.h>
using namespace std;
int a[10000000],n,k,zs,i,j,p;
struct pos
{
	int x,y;
	pos(int x1,int y1)
	{
		x = x1;y = y1;
	}
};
vector <pos> answer;
bool pd()
{
	int b = a[i];
	for (int c = i+1;c < j;c++)
	{
		b = b xor a[i];
	}
	return (b == k);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if (n <= 2)
	{
		for (int i = 0;i < n;i++)
		{
			if (a[i] == 0)zs++;
		}
		if (n == 2 && a[0] xor a[1] == k)zs ++;
		cout << zs;
		return 0;
	}
	/*else if (1 == 1)
	{
		
	}*/
	for (i = 0;i <= n;i++)
	{
		for (j = i;j <= n;j++)
		{
			if (pd())
			{
				zs++;
				//answer[p][0] = i;
				//answer[p][1] = j;
				answer.push_back(pos(i,j));
				for (int k = 0;i < answer.size()-1;k++)
				{
					if (answer[k].x == answer[answer.size()-1].x &&
					answer[k].y == answer[answer.size()-1].y)
					{
						if (answer[k].y - answer[k].x <
						answer[answer.size()-1].y - answer[answer.size()-1].x)
						{
							answer.pop_back();
							zs--;
						}
						else
						{
							answer.erase(answer.begin() + k);
							zs--;
						}
					}
				}
			}
		}
	}
	
	cout << zs;
	return 0;
}
