#include <bits/stdc++.h>
using namespace std;
long long n,m,t,money=0;
long long k[15][10005];
int f[10005];
struct st{
	int x;
	int y;
	long long mey;
};
st a[1000005];
bool cnt(st a,st b){
	return a.mey<b.mey;
}
bool fa(int x,int y){
	if(f[x]!=x){
		f[y]=x;
		while(f[f[y]]!=f[y]){
			f[y]=f[f[y]];
		}
	}else{
		f[x]=y;
		while(f[f[x]]!=f[x]){
			f[x]=f[f[x]];
		}
	}
	return true;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].mey;
	}
	for(int i=1;i<=t;i++){
		cin>>k[i][0];
		for(int j=1;j<=n;j++){
		cin>>k[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=m;j++){
			a[j].mey=min(a[j].mey,k[i][0]+k[i][a[j].x]+k[i][a[j].y]);
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(a+1,a+n+1,cnt);
	for(int i=1;i<=m;i++){
		if(f[a[i].x]!=f[a[i].y]){
			if(fa(a[i].x,a[i].y)) money+=a[i].mey;
		}
	}
	cout<<money;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
