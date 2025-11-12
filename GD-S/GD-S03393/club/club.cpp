#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

#ifdef _WIN32
double __begin_clock = clock();
#endif

#define FILE_IO_NAME "club"

constexpr int MAXN = static_cast<int>(1e5 + 10);

int T;
int n;
int half_n;

// 三个部门的人数
int a_member_count;
int b_member_count;
int c_member_count;

int is_special_case = 2;

int answer;

struct Member
{
	int a1;
	int a2;
	int a3;

	int max_value;
	
	std::tuple<int,int,int> values;
	
	bool operator<(const Member& member)
	{
		return values > member.values;
	}

	// 读取输入并且确定最大值已经其归属部门
	friend std::istream& operator>>(std::istream& is, Member& member)
	{
		is >> member.a1 >> member.a2 >> member.a3;
		if(is_special_case == 2 && (member.a3 != 0 || member.a2 != 0))
		{
			is_special_case = 1;
		}
		if(is_special_case == 1 && member.a3 != 0)
		{
			is_special_case = 0;
		}
		values = std::make_tuple(member.a1, member.a2, member.a3);
		member.max_value = std::max(member.a1,std::max(member.a2,member.a3));
		return is;
	}
};

Member members[MAXN];

inline void process_input()
{
	std::cin >> n;
	half_n = n/2;
	for(int i = 0; i < n; i++)
	{
		std::cin >> members[i];
	}
}

inline void add_to_1(const Member& member)
{
	answer += member.a1;
	a_member_count++;
}

inline void add_to_2(const Member& member)
{
	answer += member.a2;
	b_member_count++;
}

inline void add_to_3(const Member& member)
{
	answer += member.a3;
	c_member_count++;
}

inline void a3_max(const Member& current_member)
{
	if(c_member_count <= half_n)
	{
		add_to_3(current_member);
		return;
	}

	if(current_member.a1 > current_member.a2)
	{
		if(a_member_count <= half_n)
		{
			add_to_1(current_member);
			return;
		}
		add_to_2(current_member);
		return;
	}
	if(b_member_count <= half_n)
	{
		add_to_2(current_member);
		return;
	}
	add_to_1(current_member);
	return;
}

inline void a1_max(const Member& current_member)
{
	// 考虑送到第一部门
	if(a_member_count <= half_n)
	{
		add_to_1(current_member);
		return;
	}
	// 说明第一部门满了
	// 考虑送到第二个部门
	if(current_member.a2 > current_member.a3)
	{
		if(b_member_count <= half_n)
		{
			add_to_2(current_member);
			return;
		}
		// 如果 第二个部门也满了的话(不可能)，送第三个部门
		add_to_3(current_member);
		return;
	}
	if(c_member_count <= half_n)
	{
		add_to_3(current_member);
		return;
	}
	add_to_2(current_member);
	return;
}

inline void a2_max(const Member& current_member)
{
	if(b_member_count <= half_n)
	{
		add_to_2(current_member);
		return;
	}
	if(current_member.a1 > current_member.a3)
	{
		if(a_member_count <= half_n)
		{
			add_to_1(current_member);
			return;
		}
		add_to_3(current_member);
		return;
	}
	if(c_member_count <= half_n)
	{
		add_to_3(current_member);
		return;
	}
	add_to_1(current_member);
	return;
}

inline void initialize()
{
	answer = 0;
	a_member_count = 0;
	b_member_count = 0;
	c_member_count = 0;
}

inline void solve()
{
	initialize();

	process_input();
	
	// a2 == a3 == 0
	if(is_special_case == 2)
	{
		std::sort(members, members + n,
	          [](const Member& m1,const Member& m2) -> bool
				{
					return m1.a1 > m2.a2;
				}
			);
		for(int i = 0; i < half_n; i++)
		{
			answer += members[i].a1;
		}
		std::cout << answer << "\n";
		return;
	}
	
	// a3 == 0
	if(is_special_case == 1)
	{
		
	}

	std::sort(members, members + n,
	          [](const Member& m1,const Member& m2) -> bool
				{
					return m1.max_value > m2.max_value;
				}
	         );

	for(int i = 0; i < n; i++)
	{
		const Member& current_member = members[i];

		// 三个值相等，不管放到哪都是等效的，所以不用管 
		if(current_member.a1 == current_member.a2 && current_member.a2 == current_member.a3)
		{
			answer += current_member.a1;
			continue;
		}

		if(current_member.a1 > current_member.a2)
		{
			if(current_member.a1 > current_member.a3)
			{
				// 说明 a1最大
				a1_max(current_member);
				continue;
			}
			// 否则就是a3最大
			a3_max(current_member);
			continue;

		}
		// 否则就是a2较大
		if(current_member.a2 > current_member.a3)
		{
			a2_max(current_member);
		}
		// 否则就是 a3最大
		a3_max(current_member);
	}

	std::cout << answer << "\n";
}


int main()
{
	freopen(FILE_IO_NAME".in","r",stdin);
	freopen(FILE_IO_NAME".out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> T;
	while(T--)
	{
		solve();
	}

#ifdef _WIN32
	std::cerr << "Time Cost:" << (clock() - __begin_clock)/1000 << "s\n";
#endif
	return 0;
}
