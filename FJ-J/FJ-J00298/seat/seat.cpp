#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,s;
}a[110];
int n,m,seat[20][20],now,ansx,ansy;
bool cmp(node ax,node ay){
	return ax.s>ay.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i].s,a[i].x=i;
	sort(a+1,a+1+(n*m),cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i].x==1)
		{
			now=i;
			break;
		}
	}
	int ans_y,ans_x;
	if (now%n==0)ans_y=now/n;
	else ans_y=(now/n)+1; 
	if (ans_y%2==0)
		ans_x=1+(ans_y*n)-now;
	else ans_x=n-(ans_y*n-now);
	cout<<ans_y<<" "<<ans_x;
	return 0;
}

