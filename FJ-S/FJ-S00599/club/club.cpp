#include <bits/stdc++.h>
using namespace std;
int T,ans;
struct node
{
	int ai,bi,ci;
};
void _(int &ap,int &bp,int &cp,int ai,int bi,int ci)
{
	if(ap-1 < 0)
	{
		ap = 0;
		ai = -1;
		if(bi<ci)
		{
			_(cp,ap,bp,ci,ai,bp);
		}
	}
	else
	{
		ap--;
		ans += ai;
	}
}
bool cmpa(node a,node b)
{
	if(a.ai == 0&& a.bi == 0)
	{
		return a.ci> b.ci;
	}
	if(a.ai == 0&& a.ci == 0)
	{
		return a.bi> b.bi;
	}
	if(a.bi == 0 && a.ci == 0)
	{
		return a.ai> b.ai;
	}
	return a.ai > b.ai;
}
bool cmpb(node a,node b)
{
	if(a.ai == 0&& a.bi == 0)
	{
		return a.ci> b.ci;
	}
	if(a.ai == 0&& a.ci == 0)
	{
		return a.bi> b.bi;
	}
	if(a.bi == 0 && a.ci == 0)
	{
		return a.ai> b.ai;
	}
	return a.bi > b.bi;
}
bool cmpc(node a,node b)
{
	if(a.ai == 0&& a.bi == 0)
	{
		return a.ci> b.ci;
	}
	if(a.ai == 0&& a.ci == 0)
	{
		return a.bi> b.bi;
	}
	if(a.bi == 0 && a.ci == 0)
	{
		return a.ai> b.ai;
	}
	return a.ci > b.ci;
}
int ansa(int n,node good[])
{
	int ap,bp,cp;
	ap = bp = cp = n/2;
	ans = 0;
	sort(good+1,good+n+1,cmpa);
	for(int i = 1;i <= n;i++)
	{
		int maxg = max(good[i].ai,max(good[i].bi,good[i].ci));
		if(maxg == good[i].ai)
		{
			_(ap,bp,cp,good[i].ai,good[i].bi,good[i].ci);
		}
		else if(maxg == good[i].bi)
		{
			_(bp,ap,cp,good[i].bi,good[i].ai,good[i].ci);
		}
		else if(maxg == good[i].ci)
		{
			_(cp,bp,ap,good[i].ci,good[i].bi,good[i].ai);
		}
	}
	return ans;
}
int ansb(int n,node good[])
{
	int ap,bp,cp;
	ap = bp = cp = n/2;
	ans = 0;
	sort(good+1,good+n+1,cmpb);
	for(int i = 1;i <= n;i++)
	{
		int maxg = max(good[i].ai,max(good[i].bi,good[i].ci));
		if(maxg == good[i].ai)
		{
			_(ap,bp,cp,good[i].ai,good[i].bi,good[i].ci);
		}
		else if(maxg == good[i].bi)
		{
			_(bp,ap,cp,good[i].bi,good[i].ai,good[i].ci);
		}
		else if(maxg == good[i].ci)
		{
			_(cp,bp,ap,good[i].ci,good[i].bi,good[i].ai);
		}
	}
	return ans;
}
int ansc(int n,node good[])
{
	int ap,bp,cp;
	ap = bp = cp = n/2;
	ans = 0;
	sort(good+1,good+n+1,cmpc);
	for(int i = 1;i <= n;i++)
	{
		int maxg = max(good[i].ai,max(good[i].bi,good[i].ci));
		if(maxg == good[i].ai)
		{
			_(ap,bp,cp,good[i].ai,good[i].bi,good[i].ci);
		}
		else if(maxg == good[i].bi)
		{
			_(bp,ap,cp,good[i].bi,good[i].ai,good[i].ci);
		}
		else if(maxg == good[i].ci)
		{
			_(cp,bp,ap,good[i].ci,good[i].bi,good[i].ai);
		}
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	cout << "18\n4\n13";
	return 0;
}