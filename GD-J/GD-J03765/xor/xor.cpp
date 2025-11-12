#include<bits/stdc++.h>
using namespace std;
int nn[500005];
int eh(int a,int b)
{
	if(a == b) return a;
	string o,p,aa,bb;
	int l = 1;
	long long ans = 0;
	while(a)
	{
		o += (a % 2) + '0';
		a /= 2;
	}
	while(b)
	{
		p += (b % 2) + '0';
		b /= 2;
	}
	int oo = o.size() - 1,pp = p.size() - 1;
	if(oo > pp)
	{
		for(int i = 1;i <= oo - pp;i++)
		{
			p += '0';
		}
		pp = oo;
	}
	else
	{
		for(int i = 1;i <= pp - oo;i++)
		{
			o += '0';
		}
		oo = pp;
	}
	for(int i = oo;i >= 0;i--)
	{
		aa += o[i];
	}
	for(int i = pp;i >= 0;i--)
	{
		bb += p[i];
	}
	for(int i = oo;i >= 0;i--)
	{
		if(aa[i] != bb[i])
		{
			ans += l;
		}
		l *= 2;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,answ = 0,ll = 1;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&nn[i]);
	}
	for(int i = 1;i <= n;i++)
	{
		int f = nn[i];
		if(f == k)
		{
			answ++;
			continue;
		}
		for(int q = i + 1;q <= n;q++)
		{
			f = eh(f,nn[q]);
			if(f == k)
			{
				answ++;
				i = q + 1;
				break;
			}
		}
	}
	cout << answ;
	return 0;
 } 
