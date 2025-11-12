#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::find;

struct sequence
{
	int start_position,end_position;
	
	bool operator==(sequence rvalue) //返回是否没重叠 
	{
		return !((rvalue.start_position <= start_position && rvalue.end_position >= start_position) || (rvalue.start_position <= end_position && rvalue.end_position >= end_position));
	}
};



int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int seq_size,target_seq_perm_val;
	cin>>seq_size>>target_seq_perm_val;
	
	int seq[seq_size];
	
	for(int i=0;i<seq_size;i++)
	{
		cin>>seq[i];
	}
	
	vector<sequence> sequence_found;
	//何意味。 
	for(int i=0;i<seq_size;i++)
	{
		int cur_perm_val = seq[i]; //当前区间的权值  
		sequence cur_seq;
		
		cur_seq.start_position = i;  
		for(int j=i;j<seq_size;j++)
		{
			cur_seq.end_position = j;
			for(int k=i+1;k<=j;k++)
			{
				cur_perm_val = cur_perm_val xor seq[k];	
			}
			if(cur_perm_val == target_seq_perm_val)
			{
				if(find(sequence_found.begin(),sequence_found.end(),cur_seq) == sequence_found.end())
				{
					sequence_found.push_back(cur_seq);
				}
			}
		}	
	} 
	
	cout<<sequence_found.size();
	return 0;
	//神秘的石山，人和代码有一个能跑就行。 
	//改不出来，已投降    ┗( T﹏T )┛ 
	//bilibili @Insidecactus 
}
