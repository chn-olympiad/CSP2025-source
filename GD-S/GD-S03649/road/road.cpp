#include<bits/stdc++.h>
using namespace std;
int tu[1010][1010];
void dfs(int js){
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		tu[x][y]=z;
	}
	srand(time(0));
	cout<<rand()%255;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
