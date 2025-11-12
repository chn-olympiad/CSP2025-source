#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e9;
ll n,m;
ll a[121],x,y,a1,id;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a1==a[i]){
			id=i;
			break;
		}
	}
//	cout<<id<<endl;
	x=(id+n-1)/n;
	y=id-(x-1)*n;
	cout<<x<<' ';
	if(x%2==1)
	{
		cout<<y<<' ';
	}else {
		cout<<(n+1-y)<<' ';
	}
	
	return 0;
}
/*
2 2
99 100 97 98
*/