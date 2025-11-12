#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],b[100005][5],l,c[5];
void zd(long long i,long long j,long long ll)
{
	if(c[j]>n/2||b[i][j]==1)return;
	if(i==n)
	{
		l=max(l,ll);
		return;
	}
	ll+=a[i][j];
//	cout<<a[i][j]<<endl;
	i++;
	zd(i,3,ll);
	zd(i,2,ll);
	zd(i,1,ll);  
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long z=1;z<=t;z++)
	{
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		zd(1,1,0);
		zd(1,2,0);
		zd(1,3,0);
		cout<<l<<endl;
		l=0;
		for(int i=0;i<=4;i++)c[i]=0;
	}
	return 0;
}
