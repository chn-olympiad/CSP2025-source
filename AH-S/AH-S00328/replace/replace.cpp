#include <string>
#include <fstream>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr size_t buf_size = 32 * 1024;
char in_buf[buf_size], out_buf[buf_size];

constexpr ll N = 200005;
constexpr ll base = 131;
ull pow131[N];
ll n, q, ans;
string a[N], b[N], pat, mat, tmp;
ull hasha[N], hashb[N];
namespace solution1
{
	void work()
	{
	while(q--)
	{
		ans = 0;
		cin >> pat >> mat;
		for(register int i = 1; i <= n; ++i)		
		{
			for(register size_t sta = 0; sta + a[i].size() - 1 < pat.size(); ++sta)
			{
				if(pat.substr(sta, a[i].size()) == a[i])
				{
					tmp = pat;
					for(register size_t k = sta, j = 0; j < b[i].size(); ++k, ++j)
						tmp[k] = b[i][j];
					ans += tmp == mat;
				}
			}
		}
		cout << ans << "\n";
	}
}
}
inline ull get_hash(const string str)
{
	ull ret = 0;
	for(size_t i = 0; i < str.size(); ++i)
		ret = ret * base + str[i];
	return ret;
}
struct hash_string
{
	ull pre_hash[N], suf_hash[N], sz;
	hash_string(const string str)
	{
		sz = str.size();
		ull ret = 0;
		for(size_t i = 0; i < str.size(); ++i)
		{
			ret = ret * base + str[i];
			pre_hash[i] = ret;
		}
		ret = 0;
		for(int i = str.size() - 1; i >= 0; --i)
		{
			ret = ret + pow131[str.size() - i - 1] * str[i];
			suf_hash[i] = ret;
		}
	}
	inline ull replace(size_t st, size_t ed, ull hashs) //[st, ed]
	{
		if(st == 0 && ed == sz - 1) return hashs;
		if(st == 0) return suf_hash[ed + 1] + hashs * pow131[sz - ed - 1];
		if(ed == sz - 1) return hashs + pre_hash[st - 1] * pow131[sz - st];
		return suf_hash[ed + 1] + hashs * pow131[sz - ed - 1] + pre_hash[st - 1] * pow131[sz - st];
	}
};
signed main()
{
	ifstream cin("replace.in", ios::binary);
	ofstream cout("replace.out", ios::binary);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin.rdbuf()->pubsetbuf(in_buf, buf_size);
	cout.rdbuf()->pubsetbuf(out_buf, buf_size);
	
	pow131[0] = 1;
	for(int i = 1; i < N; ++i)
		pow131[i] = pow131[i - 1] * base;
	cin >> n >> q;
	for(register int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		hasha[i] = get_hash(a[i]);
		hashb[i] = get_hash(b[i]);
	}
	while(q--)
	{
		cin >> pat >> mat;
		hash_string hash_pat(pat), hash_mat(mat);
		ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(a[i].size() > pat.size()) continue;
			ull hashnow = hash_pat.pre_hash[a[i].size() - 1];
			for(int sta = 0; sta + a[i].size() - 1 < pat.size(); ++sta)
			{
				if(hashnow == hasha[i] && hash_pat.replace(sta, sta + a[i].size() - 1, hashb[i]) == hash_mat.pre_hash[mat.size() - 1])
					++ans;
				if(sta + a[i].size() == pat.size()) continue;
				hashnow = hashnow * base + pat[sta + a[i].size()] - pow131[a[i].size()] * pat[sta];
			}
		}
		cout << ans << "\n";
	}
}
	




