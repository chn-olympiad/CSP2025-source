#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int read()
{
	int x = 0,f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-'? -1 : f),c = getchar();
	while(c >= '0' && c <= '9') x = (x<<1) + (x<<3) + c - '0',c = getchar();
	return x * f;
}

const int N = 2e5 + 5,L = 5e6 + 5;

int n,q;
char s1[L],s2[L];

string to_str(char *c,int l,int r)
{
	string s; s.resize(r - l + 1);
	for(int i = l; i <= r; i++)
		s[i - l] = c[i];
	return s;
}

map<pair<string,string>,vector<pair<string,string> > > mp;

namespace Sub100_A
{
	
	void solve()
	{
		while(q--)
		{
			scanf("%s",s1 + 1); scanf("%s",s2 + 1);
			int len = strlen(s1 + 1),len2 = strlen(s2 + 1);
			if(len != len2) { printf("%d\n",0); continue; }
			
			int l = 1,r = len;
			while(s1[l] == s2[l]) l++;
			while(s1[r] == s2[r]) r--;
			
			pair<string,string> tmp = make_pair(to_str(s1,l,r),to_str(s2,l,r));
			if(mp.count(tmp) == 0) { printf("%d\n",0);  continue; }
			
			int cnt = 0;
			for(pair<string,string> p : mp[tmp])
			{
				if(p.first.size() > l - 1 || p.second.size() > (len - r)) continue;
				bool flag = 1;
				for(int i = l - 1; i >= max(1,(int)(l - (p.first).size())); i--)
					if((p.first)[(p.first).size() - (l - i)] != s1[i]) { flag = 0; break; }
				if(!flag) continue;
				for(int i = r + 1; i <= min(len,(int)(r + (p.second).size())); i++)
					if((p.second)[i - r - 1] != s1[i]) { flag = 0; break; }
				if(!flag) continue;
				cnt++;
	//			cout << to_str(s1,1,l - 1) << " " << p.first << endl;
	//			cout << to_str(s1,r + 1,len) << " " << p.second << endl;
	//			cout << endl;
			}
			
			printf("%d\n",cnt);
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n = read(),q = read();
	for(int i = 1; i <= n; i++)
	{
		scanf("%s",s1 + 1); scanf("%s",s2 + 1);
		
		int len = strlen(s1 + 1);
		int l = 1,r = len;
		while(s1[l] == s2[l]) l++;
		while(s1[r] == s2[r]) r--;
		
		if(l > r) continue;
		mp[make_pair(to_str(s1,l,r),to_str(s2,l,r))].push_back(make_pair(to_str(s1,1,l - 1),to_str(s1,r + 1,len)));
	}
	Sub100_A::solve();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

5 1
a z
bab bzb
cbabc cbzbc
dcbabcd dcbzbcd
dcbabcd dcbdbcd
edcbabcde edcbzbcde
*/

