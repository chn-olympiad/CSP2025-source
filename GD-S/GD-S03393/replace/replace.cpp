#include <iostream>
#include <string>
#include <ctime>
using std::string;

#ifdef _WIN32
double __begin_clock = clock();
#endif

#define FILE_IO_NAME "replace"

constexpr int MAXN = static_cast<int>(2e5 + 10);

std::pair<string,string> string_pairs[MAXN];
std::pair<string,string> query[MAXN];

int T;
int n;
int current_query_index; 
bool is_special = true;

string query_source,query_target;

int answer_count = 0;

inline void initialize()
{
	answer_count = 0;
}

inline void process_input()
{
	std::cin >> n >> T;
	is_special = (T == 1);
	for(int i = 0; i < n; i++)
	{
		std::cin >> string_pairs[i].first >> string_pairs[i].second;
	}
	for(int i = 0; i < T; i++)
	{
		std::cin >> query[i].first >> query[i].second;
	}
}

void dfs(int start_index,int current_length,int pair_index)
{
	if(pair_index >= n) return;
	if(start_index >= query_source.length() - string_pairs[pair_index].first.length()) return;
	if(current_length == string_pairs[pair_index].first.length())
	{
		query_source.replace(query_source.begin() + start_index,current_length-1,string_pairs[pair_index]);
		if(query_source == query_target) answer_count++;
		dfs(0,0,0);
	}
	if(query_source[start_index + current_length] != string_pairs[pair_index].first[current_length])
	{
		dfs(start_index,0,pair_index+1);
	}
	else
	{
		dfs(start_index, current_length + 1,pair_index);
	}
}

inline void solve()
{
	initialize();
	query_source = query[current_query_index].first;
	query_target = query[current_query_index].second;
	dfs(0,0,0);
	std::cout<<answer_count<<"\n";
}

int main()
{
	freopen(FILE_IO_NAME".in","r",stdin);
	freopen(FILE_IO_NAME".out","w",stdout);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	
	process_input();
	for(current_query_index = 0; current_query_index < T; current_query_index++)
	{
		solve();
	}
	
#ifdef _WIN32
	std::cerr << "Time Cost:" << (clock() - __begin_clock)/1000 << "s\n";
#endif 
	return 0;
}
