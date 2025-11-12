#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int N = 2e5+5,L = 5e6+5,Base = 31;
struct p
{
	ull h1,h2;
	bool operator<(const p &b)const
	{
		if(h1 != b.h1) return h1 < b.h1;
		return h2 < b.h2;
	}
};
int n,T,len;
ull s_hash[L],t_hash[L],powb[L];
string s1,s2;
set<p>st,st2;

ull get_hash(ull *s_hash,int l,int r) {return s_hash[r]-s_hash[l-1]*powb[r-l+1];}

bool check(int l,int r)
{
	if(st.count({get_hash(s_hash,l,r),get_hash(t_hash,l,r)}) == 0) return 0;
	st.erase({get_hash(s_hash,l,r),get_hash(t_hash,l,r)});
	return 1;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> T;
	for(int i = 1;i <= n;i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		ull s_h1 = 0,s_h2 = 0;
		for(int j = 0;j < s1.size();j++) s_h1 = s_h1*Base+s1[j]-'a'+1;
		for(int j = 0;j < s2.size();j++) s_h2 = s_h2*Base+s2[j]-'a'+1;
		st2.insert({s_h1,s_h2});
	}
	powb[0] = 1;
	for(int i = 1;i <= 5e6;i++) powb[i] = powb[i-1]*Base;
	while(T--)
	{
		int the_ans = 0;
		cin >> s1 >> s2;
		len = s1.size();
		s1 = " "+s1+" ";
		s2 = " "+s2+" ";
		int spl = -1,spr = -1;
		for(int i = 1;i <= len;i++)
		{
			s_hash[i] = s_hash[i-1]*Base+s1[i]-'a'+1;
			t_hash[i] = t_hash[i-1]*Base+s2[i]-'a'+1;
			if(s1[i] != s2[i])
			{
				if(spl == -1) spl = i;
				spr = i;
			}
		}
		st = st2;
		for(int l = 1;l <= spl;l++)
		{
			for(int r = spr;r <= len;r++)
			{
				if(check(l,r)) the_ans++;
				if(st.size() == 0) break;
			}
			if(st.size() == 0) break;
		}
		cout << the_ans << '\n';
	}
	return 0;
}
