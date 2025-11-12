#include<bits/stdc++.h>
using namespace std;
int a[105],b[105][105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,r,l;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
	  cin>>a[i];
    }
    r=a[1];
	sort(a+1,a+i+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==r) l=i;
	}
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)
		{
			if(n%2==0){
				if(y%2==0&&n*(y-1)+y-x+1==l){
					cout<<y<<' '<<x;
				}
				if(y%2==1&&n*(y-1)+x==l){
					cout<<y<<' '<<x;
				}
			}
			if(n%2!=0){
				if(y%2==0&&n*(y-1)+y-x==l){
					cout<<y<<' '<<x;
				}
				if(y%2==1&&n*(y-1)+x==l){
					cout<<y<<' '<<x;
				}
			}
		}
	}
	return 0;
}
