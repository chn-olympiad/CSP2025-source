#include<bits\stdc++.h>
using namespace std;
int a[114514][4],n,m,maxn,maxx;
bool maax=0;
void dfs(int step,int key,int sone,int stwo,int sthree){
	if(step==n+1){
		maxn=max(maxn,key);
		if(maxn==maxx)maax=1;
		return;
	}
	if(sone<n/2&&!maax)dfs(step+1,a[step][1]+key,sone+1,stwo,sthree);
	if(stwo<n/2&&!maax)dfs(step+1,a[step][2]+key,sone,stwo+1,sthree);
	if(sthree<n/2&&!maax)dfs(step+1,a[step][3]+key,sone,stwo,sthree+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	for(int k=1;k<=m;k++){
		cin>>n;
		maxn=0,maxx=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxx=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<'\n';
	}
	return 0;
}
