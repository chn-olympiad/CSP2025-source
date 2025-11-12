#include<bits/stdc++.h>
using namespace std;
long long n,m,k,vis[20005],key,u,pos;
long long x[20][10005];
struct edge{
	long long f,t,v;
}edg[1000005];
long long find(long long x){
	if(vis[x]==x){
		return x;
	}else{
		return vis[x]=x;
	}
}
void hb(long long x,long long y){
	vis[find(y)]=vis[find(x)];
	return ;
}
bool camp(edge x,edge y){
	return x.v<y.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edg[i].f>>edg[i].t>>edg[i].v;
		vis[i]=i;
	}
	for(int i=1;i<=k;i++){
		pos=0;
		cin>>x[i][1];
		if(x[i][1]==0){
			pos++;
		}
		for(int l=1;l<=n;l++){
			cin>>x[i][l+1];
			if(x[i][l+1]==0){
				pos++;
			}
		}
		if(pos==n+1){
			key++;
		}
	}
	if(key>0){
		cout<<0;
		return 0;
	}
	sort(edg+1,edg+m+1,camp);
	pos=0;
	while(key<n-1){
		pos++;
		if(find(edg[pos].f)!=find(edg[pos].t)){
			hb(edg[pos].f,edg[pos].t);
			u+=edg[pos].v;
			key++;
		}
	}
	cout<<u;
	return 0;
}
