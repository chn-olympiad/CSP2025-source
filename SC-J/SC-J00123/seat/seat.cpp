#include<bits/stdc++.h>
#define N 15
#define M 105
using namespace std;
int n,m;
int score[M];
int main()
{
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	const int num=n*m;
	for(int i=1;i<=num;i++)
	{
		cin>>score[i];
	}
	const int tmp=score[1];
	sort(score+1,score+1+num);
	int x=1,y=1;
	for(int i=num;i>=1;i--)
	{
		if(score[i]==tmp)
		{
			cout<<x<<" "<<y;
			break;
		}
		if(x%2==1)
		{
			if(y==n) x++;
			else y++;
		}
		else
		{
			if(y==1) x++;
			else y--;
		}
	}
	return 0;
}