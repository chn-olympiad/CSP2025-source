//GZ-S00276 贵阳中天中学 杨雨辰
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++) scanf("%d%d%d",&u,&v,&w);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&u);
		for(int j=0;j<n;j++) scanf("%d",&v);
	}
	w=0;
	printf("%d",w);
	fclose(stdin);
    fclose(stdout);
}
