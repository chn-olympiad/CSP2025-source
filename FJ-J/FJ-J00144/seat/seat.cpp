#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500],s,v,N,M; 
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	s=a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	while(a[v]!=s)v++;
	M=(v/n)+1;
	if(M%2==1)N=(v%m)+1;
	else N=m-v%m;
	cout<<M<<' '<<N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

