#include<bits/stdc++.h>
using namespace std;
long long ans,n,a;
int date(int i)
{
	long long m=1;
	for(int j=i;j>=0;j++)m*=j;
	ans+=m;
	if(i==n){
		cout<<ans;
		return 0;
	}
	date(i+1);
}
int main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a;
	date(3);
	return 0;
}