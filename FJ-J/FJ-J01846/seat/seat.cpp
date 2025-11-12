#include<bits/stdc++.h>
using namespace std;
int po[105];
int t;
int a=1,b=1;//a ÐÐ£¬b ÁÐ 
bool flag = true;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> po[i];
	}
	int r = po[1];
	sort(po+1,po+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(po[i] == r)
		{
			t = i;
			break;
		}
	}
	for(int i = 1;i <= n*m;i++)
	{
		if(t == i)
		{
			cout << b << " " << a << " " << endl;
			return 0;
		}
		if (flag == true)
		{
			a++;
			if(t == i)
			{
				cout << b << " " << a << " " << endl;
				return 0;
			}
		}
		else if(flag == false)
		{
			a--;
			if(t == i)
			{
				cout << b << " " << a << " " << endl;
				return 0;
			}
		}
		if(a==1&&flag == false)
		{
			i ++;
			if(t == i)
			{
				cout << b << " " << a << " " << endl;
				return 0;
			}
			b++;
			flag == true;
			continue;
		}
		if(a == n)
		{
			i++;
			if(t == i)
			{
				cout << b << " " << a << " " << endl;
				return 0;
			}
			b++;
			flag = false;
			continue;
		}
		
		
	}
	cout << b << " " <<a;
	return 0;
}
