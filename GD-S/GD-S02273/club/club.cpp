#include <bits/stdc++.h>

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int group;
	std::cin >> group;
	for(int a = 0;a < group;a++)
	{
		int ans = 0;
		int member;
		std::cin >> member;
		int memlist[member][3];
		int cost[member][3];
		int final[member];
		int least[member];
		
		int now[member][3];
		int nownum[3];
		
		memset(now,0,sizeof(now));
		memset(nownum,0,sizeof(nownum));
		
		for(int b = 0;b < member;b++)
		{
			std::cin >> memlist[b][0] >> memlist[b][1] >> memlist[b][2];
		}
		
//		std::cout << std::endl;
//		for(int b = 0;b < member;b++)
//		{
//			std::cout << memlist[b][0] << " " << memlist[b][1] << " " << memlist[b][2] << std::endl;
//		}

		for(int b = 0;b < member;b++)
		{
			int inwhere = 0;
			
			final[b] = memlist[b][0];
			for(int c = 0;c < 3;c++)  //计算max 
			{
				if(memlist[b][c] > final[b])
				{
					final[b] = memlist[b][c];
				}
			}
			
			
			for(int c = 0;c < 3;c++)  //控制now的数量 
			{
				if(final[b] == memlist[b][c])
				{
					now[nownum[c]][c] = b;
					nownum[c]++;
					inwhere = c;
					break;
				}
			}
			
			
			for(int c = 0;c < 3;c++)  //计算cost 
			{
				cost[b][c] = final[b] - memlist[b][c];	
			}
			
			
			if(inwhere != 0) least[b] = cost[b][0];
			else least[b] = cost[b][1];
			for(int c = 0;c < 3;c++)  //计算least 
			{
				if(c == inwhere) continue;
				if(cost[b][c] < least[b])
				{
					least[b] = cost[b][c];
				}
			}
		}
		
		int biggest = member/2;
		
		for(int count = 0;count < 3;count ++)
		{
			if(nownum[count] > biggest)
			{
				int leasts[nownum[count]];
				for(int b = 0;b < nownum[count];b++)
				{
					leasts[b] = least[now[b][count]];
				}
				
				std::sort(leasts, leasts + nownum[count]);
				
				for(int b = 0;b < nownum[count] - biggest;b ++)
				{
					ans = ans - leasts[b];
				}
				break;
			}
		}
		for(int b = 0;b < member;b++)
			ans += final[b];
		std::cout << ans << std::endl;
	}
	return 0;
}
