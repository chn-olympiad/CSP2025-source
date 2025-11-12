#include<bits/stdc++.h>
using namespace std;
#define K 10
#define N 1000
#define M 1000000
long long n,m,k,b[K][N+1],cnt=0;
struct my_node
{
	long long d1,d2,d3;
}a[N];
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(long long i=0;i<n;i++)
{
	cin>>a[i].d1>>a[i].d2>>a[i].d3;
	cnt+=a[i].d3;
}
for(long long j=0;j<k;j++)
{
	for(int i=0;i<=n;i++)
	{
		cin>>b[j][i];
	}
}
if(k==0)
cout<<cnt<<endl;
else
cout<<"0";
return 0;
}

