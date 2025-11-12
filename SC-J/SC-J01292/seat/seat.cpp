#include<bits/stdc++.h>
using namespace std;
int score[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	int rscore=0;
	int ri=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>score[i];
		if(i==1) rscore=score[i];
	}
	sort(score+1,score+(n*m)+1,cmp);
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<score[i]<<' ';
//	}
	for(int i=1;i<=n*m;i++)
	{
		if(score[i]==rscore)
		{
			ri=i;
			break;
		}
	}
	int rl=(ri+n-1)/n;
	int si=(ri-1)%n+1;
	if(rl%2==0) cout<<rl<<' '<<n-si+1;
	else cout<<rl<<' '<<si;
	return 0;
}