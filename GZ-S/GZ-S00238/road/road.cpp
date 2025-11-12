///GZ-00238 贵阳市第一中学 李翰霆
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,a,b,c,g=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		g=c+g;
	}
	long long s[k+2]={};
	for(int i=0;i<=k;i++)
	{
		cin>>s[i];
	}
	cout<<g+12%3;
	return 0;
}
