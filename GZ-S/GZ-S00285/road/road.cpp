//GZ-S00285 贵阳市第一中学 樊墨涵
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e4+10;
int n,a[N],b,c,ans;
struct node{
	int s,e,m;
	bool l=0,r=0;
}d[N];
struct road{
	int m1,mn[M];
}f[M];
bool cmp(node x,node y){
	return x.m<y.m;
}
bool dfs(int x){
	a[x]++;
	if(a[x]>1){
		return 1;
	}
	for(int i=1;i<=b;i++){
		if(d[i].r==0&&d[i].l==1&&d[i].s==x){
			d[i].r=1;
			dfs(d[i].e);
			a[x]=0;
			d[i].r=0;
		}else if(d[i].r==0&&d[i].l==1&&d[i].e==x){
			d[i].r=1;
			dfs(d[i].s);
			a[x]=0;
			d[i].r=0;
		}
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>b>>c;
	for(int i=1;i<=b;i++){
		cin >>d[i].s>>d[i].e>>d[i].m;
	}
	for(int i=1;i<=c;i++){
		cin >>f[i].m1;
		for(int j=1;j<=n;j++){
			cin >>f[i].mn[j];
		}
	}
	sort(d+1,d+b+1,cmp);
	for(int i=1;i<=b;i++){
		d[i].l=1;
		if(dfs(d[i].s)){
			d[i].l=0;
		}else{
			ans+=d[i].m;
		}
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
