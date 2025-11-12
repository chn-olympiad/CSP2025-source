#include<bits/stdc++.h>
using namespace std;

int sc[105];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	for(i=0;i<n*m;i++) cin>>sc[i];
	int r = sc[0],ind;
	sort(sc,sc+n*m,cmp);
	for(i=0;i<n*m;i++)
		if(sc[i] == r)
		{
			ind = i;
			break;
		}
	int x = ind/n,y = ind%n;
	if(x%2 == 1) y = n-y-1;
	cout<<x+1<<" "<<y+1;
	return 0;
}
