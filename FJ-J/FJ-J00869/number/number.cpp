#include <bits/stdc++.h>
using namespace std;
int cnt,point=1,p=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	bool vis[1000001];
	char a[1000001],maxn='0';
	cin >> s;
	int y=s.size(),q=1,o;
	for(int i = 0;i < y;i++)
	{
		if(s[i]>='0' && s[i] <= '9')
		{
			vis[i]=1;
			cnt++;
		}
	}
	for(int i = 0;i < y;i++)
	{
		if(vis[i])
		{
			a[q]=s[i];
			q++;
		}
	}
	if(q==2)
	{
		cout << a[q-1];
		return 0;
	}
	else
	{
		while(1)
		{
			if(point==cnt)break;
			if(a[p]>=maxn)
			{
				maxn=a[p];
				o=p;
				p++;
			}
			else p++;
			if(p > cnt)
			{
				swap(a[point],a[o]);
				point++;
				p=point;
				maxn=-1;
				o=0;
			}
		}
	}
		
	for(int i = 1;i <= cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}
