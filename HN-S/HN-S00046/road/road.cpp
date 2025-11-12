#include<bits/stdc++.h>
using namespace std;
struct kkk{
	int x,y,w;
}a[1000001];
struct kkks{
	int feiy,fd[10001];
}b[10];
int f[10001];
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
bool cmp(kkk aa,kkk bb){
	return aa.w<bb.w;
}
int n,m,k;
int js(int from,int to){
	int minn=INT_MAX;
	for(int i=1;i<=k;i++){
		minn=min(minn,b[i].fd[from]+b[i].fd[to]+b[i].feiy);
	}
	return minn;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
		a[m+i].x=a[i].y;
		a[m+i].y=a[i].x;
		a[m+i].w=a[i].w;
	}
	m*=2;
	for(int i=1;i<=k;i++){
		cin>>b[i].feiy;
		for(int j=1;j<=n;j++){
			cin>>b[i].fd[j];
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	long long ans=0,cnt=0,cm=0;
	for(int i=1;i<=m;i++){
		int xx=find(a[i].x),yy=find(a[i].y);
		if(xx!=yy){
			f[xx]=yy;
			ans+=a[i].w;
			cnt++;
		}
		if(cnt==n-1){
			cout<<ans<<endl;
			return 0;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%

