#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
pair<int,int> a[105];
bool cmp(pair<int,int> x,pair<int,int> y){return x.first>y.first;}

signed main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int b;
		cin>>b;
		a[i]=make_pair(b,i);
	}
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].second==1)
		{
			pos=i;
			break;
		}
	}
	int r=pos%n,c=pos/n;
	if(r!=0)
	{
		c++;
		if(c%2==0)r=n+1-r;
	}
	else
	{
		if(c%2==0)
		 	r=1;
		else 
			r=n;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
