//GZ-S00139 贵阳市第三实验中学 宋诗迪 
//图论最短路
//迪杰斯特拉？克鲁斯卡尔？ 
#include<bits/stdc++.h>
#define int long long;
using namespace std;
void Solve_time(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Solve_time();
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
