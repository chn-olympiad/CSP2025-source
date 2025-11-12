#include <iostream>
#include <cstring>
using namespace std;
int t,n,db[7][100004][6],clubnum[6],dp[7],temp,location[100004],number[6];
int f(int dbn,int num)
{
	if(num>number[dbn])
	{
		temp = 0;
		for(int o=1;o<=number[dbn];o++)
		{
			temp += db[dbn][o][location[o]];
		}
		dp[dbn] = max(dp[dbn],temp);
		return temp;
	}
	for(int l=1;l<=3;l++)
	{
		if(clubnum[l]<number[dbn]/2)
		{
			location[num] = l;
			clubnum[l] += 1;
			f(dbn,num+1);
			clubnum[l] -= 1;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int b=1;b<=t;b++)
	{
		cin >> n;
		number[b] = n;
		for(int q=1;q<=n;q++)
		{
			for(int ty=1;ty<=3;ty++)
			{
				cin >> db[b][q][ty];
			}
		}
	}
	for(int u=1;u<=t;u++)
	{
		f(u,0);
		memset(clubnum,0,sizeof(clubnum));
		memset(location,0,sizeof(location));
		cout << dp[u] << endl;
	}
	return 0;
}
