#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >q;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,tmp;i<=n*m;i++)
	{
		cin>>tmp;
		q.push(make_pair(tmp,i));
	}
	int cnt=1;
	while(q.top().second!=1)
	{
		cnt++;
		q.pop();
		
	}
	int l=(cnt-1+m)/m;
	int h=cnt-(l-1)*m;
	if(l%2==0)
		h=n-h+1;
	cout<<l<<" "<<h;
}
