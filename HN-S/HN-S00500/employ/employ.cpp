#include<bits/stdc++.h>
using namespace std;
int m,n,c[505],gui;
long long tt,ttt = 1;
bool t[505],b = 1,d = 1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i ++)
	{
		cin>>t[i];
		if(t[i] == 0)
			b = 0;
		if(t[i] == 1)
			d = 0;
		if(d)
			gui ++;
	}
		
	for(int i = 0;i < n;i ++)
		cin>>c[i];
		
	if(m == n)
	{
		if(b)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(m == 1)
	{
		sort(c,c + n);
		for(int i = 0;i < n;i ++)
			if(c[i] >= gui)
				tt ++;
		cout<<tt;
		return 0;
	}
	if(b)
	{
		for(int i = m;i <= n;i ++)
		{
			int k = i;
			ttt = 1;
			while(k <= n)
			{
				ttt *= k;
				k ++;
				if(ttt >= 998244353)
					ttt -= 998244353;
			}
			tt += ttt;
			if(tt >= 998244353)
				tt -= 998244353;
		}
		cout<<tt;
	}
	return 0;
}
