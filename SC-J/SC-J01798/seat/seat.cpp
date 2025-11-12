#include<bits/stdc++.h> 
using namespace std;
#define pq priority_queue
#define mp map
#define mkp make_pair
#define ll long long
/*
feropen
seat.ans
itn
mian
CCF
Genshin
y0
Never Gonna Give You UP~
guanzhu luogu@chenyuheng01 thank u miao~
put this in qipadaimadashang! I want to GO TV!
LOG:
[8:30]:start
[8:41]:T1 complete,start DEBUG
[9:30]:DEBUG complete(god d**med bug of map),T2 start
[9:47]:T2 complete,start DEBUG 
[9:50]:T2 complete,start T3
*/ 
int main()
{
	freopen("seat.in","r",stdin);
	
	freopen("seat.out","w",stdout);
	
	ll n,m;
	cin>>n>>m;
	ll np=n*m;
	pq<ll> que;
	ll xq;
	for(int i=0;i<np;i++)
	{
		ll t;
		cin>>t;
		if(i==0) xq=t;
		que.push(t); 
	}
	ll x=1,y=1;
	while(que.top()!=xq)
	{
		que.pop();
		if(x%2==1) y++;
		else y--;
		if(y==0) 
		{
			x++; y=1;
		}
		else if(y==n+1)
		{
			x++;
			y=n;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}