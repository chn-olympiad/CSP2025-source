//棍木。
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>
#include <stdlib.h>

using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//疑似搜索与回溯 

int64_t stick_length[7891] = {};
bool sign[7891] = {};
int64_t ans_counter = 0;
vector<int64_t> current;
int64_t stick_count;

int64_t sum()
{
	int64_t result = 0;
	for(auto val : current)
	{
		result += val;
	}
	return result;
}

void search(int64_t requirement,int64_t sum,int64_t stick_used,int64_t last_i)
{
	//大概就是边界检测和判断结果吧 
	if(stick_used == requirement)
	{
		
		int64_t max_val = 0;
		for(auto val : current)
		{
			max_val = std::max(val,max_val);
		}
		max_val *= 2;
		
		
		if(sum > max_val)
		{
			ans_counter++;
		}
		return;
	}
	
	for(int64_t i=last_i+1;i < stick_count;i++)
	{
		if(sign[i] == false)
		{
			sign[i] = true;
			current.push_back(stick_length[i]);
			search(requirement,sum + stick_length[i],stick_used+1,i);
			current.pop_back();
			sign[i] = false;
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>stick_count;
	
	
	for(int64_t i=0;i<stick_count;i++)
	{
		cin>>stick_length[i];
	}
	
	
	for(int64_t i=3;i<=stick_count;i++)
	{
		current = {};
		search(i,0,0,-1);
	}
	
	cout<<ans_counter % 998 % 244 % 353;
	return 0;
	
	//已投降，调了一个小时bug都没把bug全调出来气死了
	//靠dfs拿个部分分吧 TAT
	//┗( T﹏T )┛
	//<(＿　＿)>
}
