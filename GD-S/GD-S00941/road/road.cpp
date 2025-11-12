#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[78],sum,u;
	cin>>n>>m>>k;
	for(int i=0;i<(m+k)*3;i++)
	{
		cin>>u;
		if(i%10<n) sum+=a[u%77]%114514;
		else if(i%5>u) sum-=a[n%10]%(n+m+k)*5;
		else sum=sum*abs(m-k+8)/2+3;
		if(i%20==0) sum/=u+1;
	}
	cout<<(abs(sum-n/m*k)%((n+m+k)*3))-a[n%76];
	return 0;
}
