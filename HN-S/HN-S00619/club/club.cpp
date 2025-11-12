#include<iostream>
#include<algorithm>
using namespace std;
int t,n,ans;
int like[100005][5],perfer[100005],worse[100005];
int lose[100005],state[100005];
int choosed[5];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		choosed[1] = 0;
		choosed[2] = 0;
		choosed[3] = 0;
		for(int i = 1;i <= n;i++)
		{ 
			perfer[i] = 0;
			worse[i] = 0;
			for(int j = 1;j <= 3;j++)
			{
				cin >> like[i][j];
				if(like[i][j] > like[i][perfer[i]])
				{
					worse[i] = perfer[i];
					perfer[i] = j;
				}
				else if(like[i][j] > like[i][worse[i]]) worse[i] = j;
			}
			choosed[perfer[i]]++;
			lose[i] = like[i][perfer[i]] - like[i][worse[i]];
			ans += like[i][perfer[i]];
		}
		int toomuch = 0;
		if(choosed[1] > n / 2) toomuch = 1;
		if(choosed[2] > n / 2) toomuch = 2;
		if(choosed[3] > n / 2) toomuch = 3;
		if(!toomuch) cout << ans << '\n';
		else
		{
			int nowsize = 0;
			for(int i = 1;i <= n;i++)
			{
				if(perfer[i] == toomuch) state[++nowsize] = lose[i];
			}
			sort(state + 1,state + 1 + choosed[toomuch]);
			for(int i = 1;i <= choosed[toomuch] - n / 2;i++) ans -= state[i];
			cout << ans << '\n';
		}
	}
}
