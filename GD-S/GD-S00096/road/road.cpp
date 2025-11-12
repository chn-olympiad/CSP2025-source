#include<bits/stdc++.h>
using namespace std;
int n,m,k,vl[10][1000005];
long long cnt;
struct road{
	int v1,v2,va;
}r[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d%d%d",r[i].v1,r[i].v2,r[i].va);
	for(int i=1;i<=k;i++){
		scanf("%d",vl[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",vl[i][j]);
			if(vl[i][j]%2==0)cnt+=vl[i][j];
		}
	}
	cout<<cnt; 
	return 0;
}

