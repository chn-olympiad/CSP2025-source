#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
struct rep
{
	string s1,s2,t;
	int p;
}b[200005];
int n,q,ans;
string t1,t2;
bool cmp(rep x,rep y)
{
	return x.t.length() < y.t.length();
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> b[i].s1 >> b[i].s2;
		int st = -1,en = 0;
		string sb1 = b[i].s1;
		string sb2 = b[i].s2;
		for(int j = 0;j < sb1.length();j++)
		{
			if(sb1[j] != sb2[j])
			{
				if(st == -1) st = j;
				en = j;
			}
		}
		if(st != -1)
		{
			b[i].t = sb1.substr(st,en-st+1);
		}
		b[i].p = st;
	}
	sort(b + 1,b + n + 1,cmp);
	for(int i = 1;i <= q;i++)
	{
		cin >> t1 >> t2;
		if(t1.length() != t2.length())
		{
			cout << 0 << endl;
			continue;
		}
		int st = -1,en = 0;
		for(int j = 0;j < t1.length();j++)
		{
			if(t1[j] != t2[j])
			{
				if(st == -1) st = j;
				en = j;
			}
		}
		if(st == -1) 
		{
			cout << 0 << endl;
			continue;
		}
		ans = 0;
		for(int j = 1;j <= n;j++)
		{
			if(b[j].p == -1) continue;
			if(b[j].t == t1.substr(st,en-st+1))
			{
				if(st-b[j].p + b[j].s1.length() - 1 > t1.length()) continue;
				if(st-b[j].p < 0) continue;
				if(b[j].s1 == t1.substr(st-b[j].p,b[j].s1.length()))
				{
					if(b[j].s2 == t2.substr(st-b[j].p,b[j].s2.length()))
					{
						ans++;
					}
				}
			}
			if(b[j].t.length() > en-st+1) break;
			if(b[j].t.length() < en-st+1)
			{
				j += (n-j)/10;
				if(b[j].t.length() >= en-st+1)
				{
					while(b[j].t.length() >= en-st+1) j -= 20;
					while(b[j].t.length() < en-st+1) j++;
					j--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
