#include<bits/stdc++.h>
using namespace std;
int n,m,t,l,k=1,x=1,y=1,d=1;
int s[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)
		cin>>s[i];
	t=s[1];
	sort(s+1,s+1+l,cmp);
	int x=1,y=1;
	if(s[k++]==t)
	{		
		cout<<y<<" "<<x;
		return 0;
	}
	while(x!=n||y!=m)
	{
		if(x==n&&d==1)
			d=-1,y++;
		else if(x==1&&d==-1)
			d=1,y++;
		else
			x+=d;
		if(s[k++]==t)
		{
			cout<<y<<" "<<x;
			break;
		}
	}
	return 0;
}
