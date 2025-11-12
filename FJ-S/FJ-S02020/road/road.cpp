#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	long long z;
};
int f[10005];
node a[1000005];
int c[15][10005];
int cnt[15];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node x,node y){
	return x.z<y.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		if(x==0) cnt[0]++;
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			if(y==0) c[cnt[0]][++cnt[cnt[0]]]=j;
		}
	}
	int sum=0;
	for(int i=1;i<=cnt[0];i++){
		if(cnt[i]>=2){
			int rx=find(c[i][1]);
			for(int j=2;j<=cnt[i];j++){
				int ry=find(c[i][j]);
				if(rx==ry) continue;
				f[ry]=rx;
				sum++;
				if(sum==n-1){
					cout<<0;
					return 0;
				}
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int rx=find(a[i].x);
		int ry=find(a[i].y);
		if(rx==ry) continue;
		f[ry]=rx;
		ans+=a[i].z;
		sum++;
		if(sum==n-1){
			cout<<ans;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

