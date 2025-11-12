#include<bits/stdc++.h>

int num_cnt[10 + '0'];

void run()
{
	std::string s;
	std::cin >> s;
	for(char ch: s)
	{
		if('0' <= ch && ch <= '9')
		{
			num_cnt[ch] += 1;
		}
	}
	for(int i = '9'; i >= '0'; --i)
	{
		std::cout << std::string(num_cnt[i], i);
	}
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	run();
	return 0;
}

