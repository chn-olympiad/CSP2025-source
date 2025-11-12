#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[109];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1],k=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(p==a[i])
		{
			k=i;
			break;
		}
	}
	int t=n*2;
	int u=k%t,v=k/n;
	if(v*n!=k)
	v++;
	cout<<v<<" ";
	if(u==0)
	u=t;
	if(v%2!=0)
	{
		cout<<u;
	}
	else
	{
		cout<<t+1-u;
	}
	//cout<<"\n"<<k<<"\n"<<u<<" "<<v;
	fclose(stdin);fclose(stdout);
	return 0;
}
