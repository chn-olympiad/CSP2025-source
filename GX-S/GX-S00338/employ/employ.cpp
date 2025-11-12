#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,w;
long long ans=0,sum;
char a[1001];
int nx[1001];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	if(a[i]=='1')
	w++;
	}
	if(w==0)
	{
	cout<<0<<endl;
	return 0;
	}
	cout<<1;
	return 0;
}
