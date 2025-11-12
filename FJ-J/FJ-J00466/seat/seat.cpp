# include <bits/stdc++.h>
using namespace std;
int n,m,a[101001];
bool cmp(int A,int B){return A>B;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,i=1;
	while(a[i]!=R)
	{
		if(x%2)++y;
		else --y;
		if(!y)y=1,x++;
		if(y>n)y=n,x++;
		++i;
	}
	cout<<x<<" "<<y;
	return 0;
}
