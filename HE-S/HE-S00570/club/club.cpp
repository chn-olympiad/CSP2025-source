#include <iostream>
#include <cstdio>
using namespace std;
int maxn = 0,maxans = -1,n = 0,person[4] = {0,0,0,0},lists[100005][4] = {};
void dfs(int rounds,int ans)
{
	if(maxans <= ans)
	{
		maxans = ans;
	}
	if(rounds == n+1)
	{
		return;
	}
	for(int j = 1;j <= 3;j++)
	{
		if(person[j] + 1 <= maxn)
		{
			person[j]++;
			dfs(rounds+1,ans+lists[rounds][j]);
			person[j]--;
		}
	}
	return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        maxn = 0,maxans = -1,n = 0;
        int tmp1,tmp2,tmp3;
        person[1] = 0;
        person[2] = 0;
        person[3] = 0;
        scanf("%d",&n);
        maxn = n / 2;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
            lists[i][1] = tmp1;
            lists[i][2] = tmp2;
            lists[i][3] = tmp3;
        }
        dfs(1,0);
        printf("%d",maxans);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
