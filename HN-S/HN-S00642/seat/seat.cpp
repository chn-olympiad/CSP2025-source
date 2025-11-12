#include <iostream>
#include <algorithm>
#include <limits.h>

constexpr bool reverse_filling = 1;
constexpr bool normal_filling = 0;

using std::cin;
using std::cout;
using std::endl;
using std::swap;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	//fuck everything
	//a piece of shit
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	int total_lines,total_cols;
	cin>>total_lines>>total_cols;
	
	unsigned arr_size = total_lines * total_cols;
	int student_score[arr_size];
	for(int i = 0;i < arr_size;i++)
	{
		cin>>student_score[i];
	}
	
	int R_score = student_score[0];
	
	std::sort(student_score,student_score+arr_size,cmp);
	
	int seat[total_lines][total_cols] = {};
	
	//filling
	int cur_line = 0,cur_col = 0;
	volatile bool filling_order = normal_filling;  //能写出volatile的也是神人。 
	for(auto val : student_score)
	{
		seat[cur_line][cur_col] = val;
		if((cur_line >= total_lines - 1 && filling_order == normal_filling) || (cur_line <= 0 && filling_order == reverse_filling))
		{
			filling_order = !filling_order;
			cur_col++;
		}
		else
		{
			cur_line += (filling_order == normal_filling) ? 1 : -1;
		}
		
	}
	
	//finding
	for(int i=0;i<total_lines;i++)
	{
		for(int j=0;j<total_cols;j++)
		{
			if(seat[i][j] == R_score)
			{
				swap(i,j);
				cout<<i+1<<' '<<j+1;
				
				i = total_lines;
				break;
			}
		}
	}
	//神秘纯模拟程序非常低效，望ac 
	return 0;
}
