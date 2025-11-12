#include <iostream>
using namespace std;
int n,m,pati[505],giv;
bool ad[505];
long long cnt;
string s;
void dfs(int day)
{
	if (n-giv<m) return;
	if (day==n+1)
	{
		cnt++;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!ad[i])
		{
			ad[i]=1;
			if (pati[i]-giv>0&&s[day-1]=='1')
			{
				dfs(day+1);
			}
			else
			{
				giv++;
				dfs(day+1);
				giv--;
			}
			ad[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++) cin>>pati[i];
	dfs(1);
	cout<<cnt;
	return 0;
}
