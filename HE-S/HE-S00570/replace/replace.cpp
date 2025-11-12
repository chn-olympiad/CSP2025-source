#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct persons
{
	int xiabiao;
	int value;
	int verygreat = 0;
};
int used[4] = {0,0,0,0};//1 = a 2 = b 3 = c
int extra_ans = 0,maxn;
vector <int> in_liness;
persons newlists_a[100005];
persons newlists_b[100005];
persons newlists_c[100005];
persons lists_a[100005];
persons lists_b[100005];
persons lists_c[100005];
void dfs(int rounds = 0,int ansed = 0)
{
	
	if(rounds == in_liness.size() - 1)
	{
		if(ansed >= extra_ans)
		{
			extra_ans = ansed;
			return;
		}
	}
	for(int l = 1;l <= 3;l++)
	{
		int xiabiao = in_liness[rounds];
		if(used[l] + 1 <= maxn)
		{
			if(l == 1 && lists_a[xiabiao].verygreat == 1)
			{
				dfs(rounds+1,ansed+lists_a[xiabiao].value);
			}
			if(l == 2 && lists_b[xiabiao].verygreat == 1)
			{
				dfs(rounds+1,ansed+lists_b[xiabiao].value);
			}
			if(l == 3 && lists_c[xiabiao].verygreat == 1)
			{
				dfs(rounds+1,ansed+lists_c[xiabiao].value);
			}
		}
	} 
	return;
}
bool cmp(persons a,persons b)
{
	return a.value > b.value;
}
int main()
{
    freopen("club5.in","r",stdin);
    freopen("club5.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	extra_ans = 0;
    	int n,tmp1,tmp2,tmp3,ans = 0;
    	used[1] = 0;
		used[2] = 0;
		used[3] = 0;//1 = a 2 = b 3 = c
    	scanf("%d",&n);
    	maxn = n / 2;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
			newlists_a[i].value = tmp1;
			newlists_b[i].value = tmp2;
			newlists_c[i].value = tmp3;
			lists_a[i].value = tmp1;
			lists_b[i].value = tmp2;
			lists_c[i].value = tmp3;
			newlists_a[i].xiabiao = i;
			newlists_b[i].xiabiao = i;
			newlists_c[i].xiabiao = i;
		}
		sort(newlists_a+1,newlists_a+1+n,cmp);
		sort(newlists_b+1,newlists_b+1+n,cmp);
		sort(newlists_c+1,newlists_c+1+n,cmp);
		for(int i = 1;i <= maxn;i++)
		{
			lists_a[newlists_a[i].xiabiao].verygreat = 1;
			lists_b[newlists_b[i].xiabiao].verygreat = 1;
			lists_c[newlists_c[i].xiabiao].verygreat = 1;
		}
		for(int i = 1;i <= n;i++)
		{
			if(lists_a[i].verygreat == 1 || lists_b[i].verygreat == 1 || lists_c[i].verygreat == 1)
			{
				if(!((lists_a[i].verygreat == 1 && lists_b[i].verygreat == 1) ||
				(lists_c[i].verygreat == 1 && lists_b[i].verygreat == 1)))//if only 1 great!
				{
					if(lists_a[i].verygreat == 1)
					{
						ans += lists_a[i].value;
						used[1]++;
					}
					else if(lists_b[i].verygreat == 1)
					{
						ans += lists_b[i].value;
						used[2]++;
					}
					else if(lists_c[i].verygreat == 1)
					{
						ans += lists_c[i].value;
						used[3]++;
					}
				}
				else//if not only 1 great!(attacked.)
				{
					in_liness.push_back(i);
				}
			}
		}
		//solve the attacked!
		int solving;
		dfs(0,0);
		ans += extra_ans;
		cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
