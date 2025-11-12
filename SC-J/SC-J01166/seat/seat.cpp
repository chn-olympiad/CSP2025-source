#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int n,m,a,s,st;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<n*m;i++)
	{
		cin>>a;
		if(a>s) st++;
	}
	int haved=st/n;
	cout<<haved+1<<" ";
	if((haved+1)%2==1)//从上往下
	{
		cout<<st-haved*n+1;
	 } 
	else//从下往上 
	{
		cout<<n-(st-haved*n);
	}
	return 0;
}
//100+100+0+0=200