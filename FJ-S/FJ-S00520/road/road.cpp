#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool a[1005][1005]={false};
priority_queue<int,vector<int>,less<int> > pq;
struct cheng{
	int u;
	int v;
	int w;
}cs[10005];
struct xiang{
	int c;
	int a[10005]={0};
}xz[12];
bool liantong(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==false){
				return false;
			}
		}
	}
	return true;
}
void xiulu(int x,int sum){
	if(liantong()||x>n){
		pq.push(sum);
		return;
	}
	xiulu(x+1,sum);//²»ÐÞ
	sum+=cs[x].w;
	a[cs[x].v][cs[x].u]=true;
	a[cs[x].u][cs[x].v]=true;
	xiulu(x+1,sum);
	sum-=cs[x].w;
	a[cs[x].v][cs[x].u]=true;
	a[cs[x].u][cs[x].v]=true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	cin>>m;
	cin>>k;
	for(int i=1;i<=m;i++){
		cin>>cs[i].u>>cs[i].v>>cs[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>xz[i].c;
		for(int j=1;j<=n;j++){
			cin>>xz[i].a[j];
		}
	}
	xiulu(1,0);
	cout<<pq.top();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
