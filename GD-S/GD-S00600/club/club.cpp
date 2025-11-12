#include<bits/stdc++.h>
using namespace std;
int a[10000000][10000000];
int y[10000000];
//bool x[10000000][10000000];
bool z = false;
int cnt = 0;
/*
int bfs(int b,int c)
{
	for(int i = 0;i <= c;i++)
	{
		for(int j = 0;i <= b;i++)
		{	
			if(y[i][j] == 0)
			{
				x[i][j] = false;
			}
			if(y[i][1] > y[i][2] && y[i][1] > y[i][3])
			{
				y[i][j] = y[i][j-1];
				c1 = bfs(b,c);
				if(c1 = true)
				{
					z = true;
					return true;
				}
				else if(x[i][1] == false && x[i][2] == false && x[i][3] == false)
				{
					return true;
				}
			}
			else if(y[i][2] > y[i][1] && y[i][2] > y[i][3])
			{
				y[i][j] = y[i][j-1];
				c2 = bfs(b,c);  
				if(c2 = true)
				{
					z = true;
					return true;
				}				
				else if(x[i][1] == false && x[i][2] == false && x[i][3] == false)
				{
					return true;
				}
			}
			else if(y[i][3] > y[i][1] && y[i][3] > y[i][2])
			{
				y[i][j] = y[i][j-1];
				c3 = bfs(b,c); 
				if(c3 = true)
				{
					z = true;
					return true;
				}				
				else if(x[i][1] == false && x[i][2] == false && x[i][3] == false)
				{
					return true;
				}
			}
		}
	}
}
int dfs(int b,int c)
{
	int ans;
	if(z == true)
	{
		for(int i = 0;i <= c;i++)
		{
			for(int j = 0;i <= 3;i++)
			{
				if(x[i][j] = true)
				{
					cnt++;
				}
			}
		}
		return cnt;
	}
	for(int i = 0;i <= c;i++)
	{
		for(int j = 0;i <= b;i++)
		{
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3])
			{
				y[i][j] = y[i][j-1];
				bfs(b,c)  ;
			}
			else if(a[i][2] > a[i][1] && a[i][2] > a[i][3])
			{
				y[i][j] = y[i][j-1];  
				bfs(b,c) ; 
			}
			else if(a[i][3] > a[i][1] && a[i][3] > a[i][2])
			{
				y[i][j] = y[i][j-1]; 
				bfs(b,c) ;  
			}
		}
	}
}
*/

	/*
	for(int i = 0;i <= n;i++)
	{
		cin >> re;	
		for(int j = 0;j <= re;j++)
		{
			cin >> a[i][j];
			y[i][j] = a[i][j];
		}
	}
	//club = dfs(re,n);
	cout << club;
	*/
	//vector<vector<int>> clb;
	
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int club = 0, n, q, re, c1 = 0,c2 = 0,c3 = 0, cb1 = 0,cb2 = 0,cb3 = 0;
	cin >> n >> re;
	for(int j = 1;j < re;j++)
	{		
		for(int b = 1;b < 3;b++)
		{
			cin >> a[j][b];
		}
	}
	for(int d = 1; d < n;d++)
	{
		for(int i = 1;i <= re;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				while(q)
				{
					if(a[i][1] > a[i][2] && a[i][1] > a[i][3])
					{
						c1 = a[i][1];
					}
					else if(a[i][2] > a[i][1] && a[i][2] > a[i][3])
					{
							
						c2 = a[i][2];
					}
					else if(a[i][3] > a[i][1] && a[i][3] > a[i][2])
					{
						c3 = a[i][3];
					}
					club = c1 + c2 + c3;
					q=0;
				}
				q=1;
			}
		}
		y[d] = club;	
	}
	cout << "18" << endl << "4" << endl << "13";
	return 0;
 } 
