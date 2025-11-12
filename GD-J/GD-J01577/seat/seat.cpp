#include<bits/stdc++.h>
using namespace std;
long long n,m,l,a[1919],ax;
bool cp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
		if(i==1) l=a[i];
	}
	sort(a+1,a+1+n*m,cp);
	for(int i=1;i<=n*m;++i)
		if(a[i]==l)
		{ 
			ax=i/m;
			if(i%m!=0) ax++;
			cout<<ax<<" ";
			if(ax%2==1)
			{
				if(i%m==0) cout<<m;
				else cout<<i%m;
			}
			else
			{
				if(i%m==0) cout<<1;
				else cout<<m-i%m+1;
			}
			break;
		}
	return 0;
}
