#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int t[110],q=1,s[110];
int n, m, x = 1, y = 1, ans1, ans2;//ÐÐ£¬ÁÐ 
int r;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> t[i];
		q++;
	}
	r = t[1];
	sort(t, t + q);
	int aa=1;
	for(int i = n*m; i>=1;i--)
	{
		s[aa]=t[i];
		aa++;
	}
	for(int i = 1; i <= n * m; i++)
	{
		a[x][y] = s[i];
		if(a[x][y]==r){
			cout<<y<<' '<<x<<endl;
			return 0;
		}
		if(x == n&&y%2!=0)
		{
			y++;
		}
		else if(y%2!=0&&x!=n)
		{
			x++;
		}
		else if(y%2==0&&x!=1)
		{
			x--;
		}
		else if(x==1&&y%2==0)
		{
			y++;
		}
		
		
	}
	
	
	return 0;	
} 
