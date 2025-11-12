#include<bits/stdc++.h>
using namespace std;
int n,m,t,sum;
struct node{
	int x,y,k;
}a[10000];
int ka[10000];
int main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].k;
	}
	for(int i=1;i<=n;i++) sum+=a[i].k;
	cout<<sum;
	return 0;
}
