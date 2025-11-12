#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,x,xu=0,c,r;
	cin>>n>>m>>a1;
	q.push(a1);
	for(int i=2;i<=n*m;i++)
	{
		cin>>x;
		q.push(x);
	}
	while(1)
	{
		xu++;
		if(a1==q.top())
			break;
		q.pop();
	}
	
	if(xu%n==0) c=xu/n;
	else c=xu/n+1;
	xu=xu%n;
	
	if(c%2==1) 
		if(xu!=0) r=xu;
		else r=n;
	else r=n-xu+1;
	cout<<c<<" "<<r;
	return 0;
}
