//GZ-S00421 毕节七星关东辰实验学校 赵云霄
#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long s1[10005][10005],s2[10005][10005];
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		s[x][y]=z;
		ans+=z;
	}
	printf("%lld",ans);
	return 0;
 } 
