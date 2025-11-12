#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,sum[100099],k,a[10009][120323],l;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(i=1;i<=m;i++)	{
		cin>>k;
	}
	for(i=1;i<=m;i++)
	{
		cin>>l;
		sum[i]+=l;
		for(j=1;j<=n;j++) 
		{
		cin>>a[i][j];
		sum[i]+=a[i][j];	
		}
	}
	sort(sum+1,sum+m+1);
	cout<<sum[1];
	return 0;
}

