#include<bits/stdc++.h>
using std::vector;
using std::string; 
//using std::array;

int n, q;

//struct change_info
//{
//	// 重合部分 
//	int before_size;
//	
//	// 元变换 
//	struct mete_change
//	{
//		string s1, s2;
//		int pos;
//		bool is_same(mete_change c2)
//		{
//			return (s1 == c2.s1)&&(s2 == c2.s2)&&(pos == c2.pos);
//		}
//	};
//	vector<mete_change> mete_info;
//	
//	bool is_same(change_info if2)
//	{
//		return mete_info == if2.mete_info;
//	}
//};

int hasher(string s)
{
	//int constexpr IN = 131;
	int ans = 0;
	for (char* i = &*s.begin(); i != &*s.end(); ++i)
	{
		ans *= 131;
		ans += *i;
	}
	return ans + 114514;
}

int hasher2(string s1, string s2)
{
	return (hasher(s1) + 124) * (hasher(s2) + 1028);
}

struct change_info
{
	string pre, cha1, cha2, last;
} ;

change_info save_change(string str1, string str2)
{
	change_info res;
	int ss = str1.size();
	int i;
	for(i = 0; (str1[i] == str2[i]); ++i)
	{
		//res.pre.push_back(str1[i])
	}
	res.pre = str1.substr(0, i);
	int i2;
	for(i2 = ss - 1; (str1[i2] == str2[i2]); --i2)
	{
		
	}
	i2 = ss - i2 - 1 ;
	if(i2 > 0)
	res.last = str2.substr(ss - i2, i2);
	res.cha1 = str1.substr(i, ss - i - i2);
	res.cha2 = str2.substr(i, ss - i - i2);
	//std::cout << "clk:  " << res.pre << " | " << res.cha1 << " |  " << res.cha2 << "  | " << res.last << "   \n";
	return res;
}

struct trie
{
	int node = 0;
	vector<vector<int> > data;
	vector<vector<int> > end;
	
	trie()
	{
		data.push_back(vector<int>(26));
		end.push_back(vector<int>());
	}
	
	void insert(string s)
	{
		int root = 0;
		node += 1;
		for(int i = 0; i < s.size(); ++i)
		{
			int ch = s[i] - 'a';
			if(data[root][ch] != 0)
			{
				root = data[root][ch];
			}
			else
			{
				data[root][ch] = data.size();
				data.push_back(vector<int>(26));
				end.push_back(vector<int>());
				root = data[root][ch];
			}
		}
		end[root].push_back(node);
	}
	
	vector<int> find(string s)
	{
		int root = 0;
		vector<int> ans;
		for(int i = 0; i < s.size(); ++i)
		{
			for(int j = 0; j < end[root].size(); ++j )
			{
				ans.push_back(end[root][j]);
			}
			
			int ch = s[i] - 'a';
			if(data[root][ch] != 0)
			{
				root = data[root][ch];
			}
			else
			{
				return ans;
			}
		}
		for(int j = 0; j < end[root].size(); ++j )
		{
			ans.push_back(end[root][j]);
		}
		return ans;
	}
};

string fread()
{
	char ch = '1';
	string ans;
	while(ch < 'a' || ch > 'z')
	{
		ch = getchar();
	}
	while(ch >= 'a' && ch <= 'z')
	{
		ans.push_back(ch);
		ch = getchar();
	}
	return ans;
}

int freadn()
{
	char ch = 'a';
	int ans = 0;
	while(ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}

struct all_info
{
	struct meta_info
	{
		trie pre, last;
		//string ch1, ch2;
		int hashv;
		//bool valie = 0;
	};
	
	std::map<int, meta_info> infos;
	
	void insert(change_info ifo)
	{
		int h = hasher2(ifo.cha1, ifo.cha2);
		infos[h].hashv = h;
		infos[h].pre.insert(ifo.pre);
		infos[h].last.insert(ifo.last);
		//infos[h].valie = 1;
	}
	
	int ask(change_info ifo)
	{
		int h = hasher2(ifo.cha1, ifo.cha2);
		if(infos.find(h) == infos.end())
		{
			return 0;
		}
		int ans = 0;
		std::set<int> l;
		vector<int> x;
		x = infos[h].pre.find(ifo.pre);
		for(int i = 0; i < x.size(); ++i)
		{
			l.insert(x[i]);
			//printf("%d ", x[i]);
		}
		//printf("\n");
		x = infos[h].last.find(ifo.last);
		for(int i = 0; i < x.size(); ++i)
		{
			if(l.find(x[i])!=l.end())
			{
				ans += 1;
			}
			//printf("%d ", x[i]);
		}
		//printf("\n");
		return ans;
	}
}afo;

void run()
{                
	int n, q;
	//scanf("%d%d", &n, &q);
	std::cin >> n >> q;
	//n = freadn();
	//q = freadn();
	for(int i = 0; i < n; ++i)
	{
		string s1, s2;
		std::cin >> s1 >> s2;
		//s1 = fread();
		//printf("%s\n",s1.data());
		//s2 = fread();
		//printf("%s\n",s2.data());
		if(s1 != s2)
		{
			change_info chi = save_change(s1, s2);
			afo.insert(chi);
		}
	}
	for(int i = 0; i < q; ++i)
	{
		string s1, s2;
		std::cin >> s1 >> s2;
		//s1 = fread();
		//printf("%s\n",s1.data());
		//s2 = fread();
		//printf("%s\n",s2.data());
		change_info chi = save_change(s1, s2);
		std::cout << afo.ask(chi) << "\n";
	}
}

signed main()
{
	freopen("replace.in", "r",stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	run();
	return 0;
}

