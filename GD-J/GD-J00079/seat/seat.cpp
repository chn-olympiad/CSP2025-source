#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node
{
	int sc,id;
}a[105];
bool cmp(node x,node y)
{
	return x.sc>y.sc;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[(j-1)*n+i].sc;
			a[(j-1)*n+i].id=(j-1)*n+i;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[(j-1)*n+i].id==1)
			{
				if(j%2==1)  cout<<j<<" "<<i;
				else  cout<<j<<" "<<n-i+1;
				return 0;
			}
		}
	}
	return 0;
} 
