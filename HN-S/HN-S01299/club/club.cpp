#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int t,n,happy[maxn][3],limit;
long long maxhappy;
// ∑÷ a,b,c ≤ø√≈ 
void happi(int who,long long nowscore,int aa,int bb,int cc)
{
	if(who==n)
	{
		if(aa<=limit && bb<=limit && cc<=limit)
		{
			maxhappy=max(maxhappy,nowscore);
			return;
		}
		else return;
	}
	else
	{
		happi(who+1,nowscore+happy[who+1][1],aa+1,bb,cc);
		happi(who+1,nowscore+happy[who+1][2],aa,bb+1,cc);
		happi(who+1,nowscore+happy[who+1][3],aa,bb,cc+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int te=1;te<=t;te++)
	{
		maxhappy=-1;
		cin>>n;
		limit=n/2;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>happy[i][j];
		happi(0,0,0,0,0);
		cout<<maxhappy<<endl;
	}
	return 0;
}
