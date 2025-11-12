#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef double llf;
//----------------------
int n,m;
int score,cnt,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=1;
	cin>>score;
	for(int i=1,t;i<=n*m-1;++i)
	{
		cin>>t;
		if(t>score)++cnt;
	}
	
	if(cnt%n==0)
	{
		x=cnt/n;
		if((cnt/n)%2==1) y=n;
		else y=1;
	}
	else
	{
		x=cnt/n+1;
		if((cnt/n)%2==1) y=n-(cnt%n)+1;
		else y=cnt%n;
	}
	
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

