#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int len,a[105],d[15][15],n,m,t,u = 1,w = 1;
int c,r,x,y;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	ifstream fin("seat3.in");
	ofstream fout("seat3.out"); 
	fin >> n >> m;
	len = n * m;
	for (int i = 1;i <= len;i++)
		fin >> a[i];
	t = a[1];
	sort(a + 1,a + 1 + len,cmp);
	x = m,y = 1;
	for (int i = 1;i <= len;i++)
	{
		d[x][y] = a[i];
		if (u == 1)
		{
			if (x == 1)
				y ++,u = (u + 1) % 2;
			else
				x --;
		}
		else if (u == 0)
		{
			if (x == m)
				y ++,u = (u + 1) % 2;
			else
				x ++;
		}
	}
	for (int i = n,v = 1;i >= 1;i --,v ++)
	{
		for (int j = 1,w = 1;j <= m;j++,w ++)
		{
			if (d[i][j] == t)
			{
				c = w;
				r = v;
				break;
			}
		 } 
	}
	fout << c << ' ' << r;
	return 0;
}
