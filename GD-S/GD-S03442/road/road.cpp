#include<bits/stdc++.h>
using namespace std;
long long a[11541],b[114514],c[114514];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		x+=c[i];
	}
	cout<<x;
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

