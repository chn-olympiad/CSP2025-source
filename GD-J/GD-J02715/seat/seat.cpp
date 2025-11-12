#include<bits/stdc++.h>
using namespace std;
int n,m,b[105],nl,c,r,bl;
int cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	bl=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==bl)
		{
			nl=i;
			break;
		}
	}
	if(nl%n==0)c=nl/n,nl=n;
	else c=nl/n+1,nl=nl%n;
	if(c%2==1)r=nl;
	else r=n-nl+1;
	cout<<c<<" "<<r;
	
	return 0;
} 
