#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int score,cnt=0;
	cin>>score;
	int c;
	while(cin>>c)
	{
		if(c>score)
		cnt++;
	}
	int a,b;
	a=(cnt/n)+1;
	int t=cnt%n;
	if(a%2==1)
	b=t;
	else
	b=n+1-t;
	cout<<a<<' '<<b;
	return 0;
}
