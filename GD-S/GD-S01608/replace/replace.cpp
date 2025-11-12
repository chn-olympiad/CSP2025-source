#include <bits/stdc++.h>
using namespace std;
#define ll long long

const unsigned ll p = 1313131;
const int _  = 2e5 + 5;

map <unsigned ll,int> hsh;

vector <int> G[_];


inline int read()
{
	int w = 1,f = 0;
	char c = getchar();
	while(c < '0' or c > '9'){if(c == '-') w = -1;c = getchar();}
	while(c >= '0' and c <= '9') f = f * 10 + c - '0',c = getchar();
	return w * f; 
}

int pos[_],pos2[_];
unsigned ll cm[5000005];

unsigned ll t1[_],t2[_];
unsigned ll gethsh(unsigned ll *hs,int l,int r)
{
	return hs[r] - hs[l - 1] * cm[r - l + 1];
}

int n,q;

unsigned ll fz(string a,string b)//·×ÕùÓ¡¼Ç 
{
	
}

unsigned ll h1[5000003],h2[5000003];

int cnt;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read();
	q = read();
	cm[0] = 1;
	for(int i = 1;i <= 5000003;i++)
		cm[i] = cm[i - 1] * p;
	for(int i = 1;i <= n;i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		unsigned ll t = 0;
		int len = s1.length();
		s1 = '#' + s1;
		s2 = '#' + s2;
		for(int j = 1;j <= len;j++)
		{
			t1[j] = t1[j] * p + s1[j];
			t2[j] = t2[j] * p + s2[j];
			if(pos[i] == 0 and s1[j] != s2[j]) pos[i] = j;
		}
		for(int j = len;j > 0;j--)
		{
			if(s1[j] != s2[j]) 
			{
				pos2[i] = j;
				break;
			}
		}
		for(int j = pos[i];j <= pos2[i];j++)
		{
			t = t * p + 2 * s2[j] - s1[j];
		}
		if(!hsh[t]) hsh[t] = ++cnt;
		G[hsh[t]].push_back(i);
//		cout << pos[i] << " " << pos2[i] << " " << t << " " << hsh[t] << " " << i << endl;
//		for(int j = pos[i)
	}
	h1[0] = h2[0] = 0;
	while(q--)
	{
		string s1,s2;
		cin >> s1 >> s2;
		s1 = '#' + s1;
		s2 = '#' + s2;
		int len = s1.length() - 1;
		unsigned ll t = 0;
		int pos1 = 0,pos3 = 0;
		for(int j = 1;j <= len;j++)
		{
			h1[j] = h1[j - 1] * p + s1[j];
			h2[j] = h2[j - 1] * p + s2[j];
			if(pos1 == 0 and s1[j] != s2[j]) pos1 = j;
		}
		for(int j = len;j > 0;j--)
		{
			if(s1[j] != s2[j]) 
			{
				pos3 = j;
				break;
			}
		}
		for(int j = pos1;j <= pos3;j++)
		{
			t = t * p + 2 * s2[j] - s1[j];
		}
		int k = hsh[t];
		int ans = 0;
		for(int i : G[k])
		{
//			cout << i << endl; 
			++ans; 
//			ans += gethsh(h1,pos1 - pos[i] + 1,pos3 + pos2[i] - pos[i]) == t1[i] and gethsh(h2,pos1 - pos[i] + 1,pos3 + pos2[i] - pos[i]) == t2[i];
		}
		cout << ans << endl;
	}
	return 0;
} 
