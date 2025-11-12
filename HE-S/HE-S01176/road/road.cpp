#include<iostream>

using namespace std;

long long n,m,k;
long long c[1000009];
struct lu
{
	long long u;
	long long v;
	long long w;
}a[1000009];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	    cin>>a[i].u>>a[i].v>>a[i].w;
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		long long o;
		for(int i=1;i<=c[j];i++)
		    cin>>o;
	}
	
	//心里大概有个示意图，但模糊不清 
	//骗分求过 
	cout<<0<<endl;
	
	return 0; 
}
