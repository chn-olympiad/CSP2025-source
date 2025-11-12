#include<bits/stdc++.h>
using namespace std;
int n;
int N[10005][4];
int maxans = INT_MIN;
int M[4];
int cnt = 0;
void solve(int student)
{
	if(student > n)
	{
		maxans = max(maxans,cnt);
		return;
	}
	for(int i = 1;i <= 3;i++)
	{
		if(M[i] * 2 >= n) continue;
		M[i]++;
		cnt += N[student][i];
		solve(student + 1);
		cnt -= N[student][i];
		M[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i = 1;i <= t;i++)
	{
		for(int j = 1;j <= 3;j++) M[j] = 0;
		maxans = INT_MIN;
		cnt = 0;
		cin>>n;
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= 3;k++)
			{
				cin>>N[j][k];
			}
		}
		solve(1);
		cout<<maxans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
