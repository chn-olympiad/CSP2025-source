#include <iostream>
#include <vector>
#include <algorithm>

/*
Program Overview:
Greedy algorithm
*/

void process()
{
	int numMember;
	std::cin >> numMember;
	std::vector<std::vector<int>> members(numMember, std::vector<int>(3));
	std::vector<std::vector<int>> arrange(3, std::vector<int>());
	for (int id = 0; id < numMember; id++)
	{
		std::cin >> members[id][0] >> members[id][1] >> members[id][2];
		int maxVal = std::max(std::max(members[id][0], members[id][1]), members[id][2]);
		if (maxVal == members[id][0])
			arrange[0].push_back(id);
		else if (maxVal == members[id][1])
			arrange[1].push_back(id);
		else
			arrange[2].push_back(id);
	}
	
	int totVal = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int stu = 0; stu < arrange[i].size(); stu++)
		{
			totVal += members[arrange[i][stu]][i];
		}
	}
	
	int overId = -1;
	for (int i = 0; i < 3; i++)
	{
		if (arrange[i].size() > numMember / 2)
		{
			overId = i;
		}
	}
	if (overId != -1)
	{
		std::vector<bool> changed(numMember);
		std::vector<std::pair<int, int>> loss;
		for (int stu = 0; stu < arrange[overId].size(); stu++)
		{
			int stuId = arrange[overId][stu];
			for (int other = 0; other < 3; other++)
			{
				if (overId != other)
					loss.emplace_back(members[stuId][overId] - members[stuId][other], stuId);
			}
		}
		for (int i = 0; i < 3; i++)
			std::sort(loss.begin(), loss.end());
		int changeCnt = arrange[overId].size() - numMember / 2;
		for (int i = 0; i < loss.size() && changeCnt; i++)
		{
			if (!changed[loss[i].second])
			{
				changed[loss[i].second] = true;
				changeCnt--;
				totVal -= loss[i].first;
			}
		}
	}
	
	std::cout << totVal << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int numGroup;
	std::cin >> numGroup;
	while (numGroup--)
	{
		process();
	}
	
	return 0;
}
