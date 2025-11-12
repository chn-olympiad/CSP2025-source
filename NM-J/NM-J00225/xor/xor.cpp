#include <bits/stdc++.h>
using namespace std;
int n;
long long k,cnt,t;
struct xo
{
	long long num,orplus;
}a[5000010];
bool b[5000010];
bool ifs(int l,int r)
{
	for(int i = l;i <= r;i++)
	{
		if(b[i] == true)
		{
			return false;
		}
	}
	return true;
}
void se(int l,int r)
{
	for(int i = l;i <= r;i++)
	{
		b[i] = true;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].num;
		if(i == 1) a[1].orplus = a[1].num;
		else
		{
			a[i].orplus = a[i - 1].orplus ^ a[i].num;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(i == 1 && a[1].num == k) 
		{
			if(b[1] == false)
			{
				cnt++;
				b[1] = true;	
			}
		}
		else if(a[i].num == k && b[i] == false)
		{
			cnt++;
			b[i] = true;
		}
		else
		{
			for(int j = 1;j < i;j++)
			{	
				if((a[i].orplus ^ a[j].orplus) == k && ifs(j,i))
				{   
					se(j,i);
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
