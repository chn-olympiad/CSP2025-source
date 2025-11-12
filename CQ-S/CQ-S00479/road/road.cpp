#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,maxm=1e4+10;
int n,m,k,f[maxm],c[15],d[15][maxm];
struct node{int x,y,data;}a[maxn];
bool cmp(node x,node y){
	return x.data<y.data;
}
int find(int x){
	if(x==f[x])return f[x];
	else return f[x]=find(f[x]);
} 
bool check(){
	for(int i=1;i<=n;i++){
		if(c[i]!=0)return 0;
	}
	return 1;
}
int main(){
//	freopen("road3.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].data;
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=n;i++)f[i]=i;
		int cnt=0,sum=0;
		for(int i=1;i<=m&&cnt<n;i++){
			int x=find(a[i].x),y=find(a[i].y);
			if(x==y)continue;
			f[x]=y,sum+=a[i].data;
		}
		cout<<sum<<"\n";
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>d[i][j];
	}
	if(check()){
		for(int i=1;i<=k;i++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=n;y++)a[++m]={x,y,d[i][y]+d[i][x]};
			}
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=n;i++)f[i]=i;
		int cnt=0,sum=0;
		for(int i=1;i<=m&&cnt<n;i++){
			int x=find(a[i].x),y=find(a[i].y);
			if(x==y)continue;
			f[x]=y,sum+=a[i].data;
		}
		cout<<sum<<"\n";
	}
	return 0;
}

/*
4 5 1
1 2 1
1 3 2
2 3 2
3 4 1
4 5 1
0 1 1 1 1
*/
