#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x;
	int y;
	int z;
	int bh;
};
edge e[4000010];
int cnt;
int p[10010],c[11],vis[10010];
bool cmp(edge x,edge y){
	return x.z<y.z;
}
int f(int x){
	if(x==p[x]){
		return x;
	}
	return p[x]=f(p[x]);
}
void m(int x,int y){
	p[f(x)]=f(y);
}
int d[11][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int N,M,K;
	cin>>N>>M>>K;
	for(int i=1;i<=M;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
		e[i].bh=0;
	}
	cnt=M;
	for(int j=1;j<=K;j++){
		cin>>c[j];
		for(int i=1;i<=N;i++){
			int tp;
			cin>>tp; 
			e[++cnt].x=j+N,e[cnt].y=i,e[cnt].z=c[j]+tp,e[cnt].bh=j;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(e[i].bh!=0){
			d[e[i].bh][e[i].y]=i;
		}
	}
	for(int i=1;i<=N;i++){
		p[i]=i;
	}
	long long int ans=0;
	int tot=0,dot=N;
	for(int i=1;i<=cnt;i++){
		//cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].z<<" "<<e[i].bh<<endl;
		if(f(e[i].x)!=f(e[i].y)){
			if(e[i].bh==0){
				m(e[i].x,e[i].y);
				tot++;
				ans+=e[i].z;
			}else{
				m(e[i].x,e[i].y);
				tot++;
				dot++;
				ans+=e[i].z;
				if(vis[e[i].bh]==0){
					for(int j=1;j<=N;j++){
						if(d[e[i].bh][j]!=i){
							e[d[e[i].bh][j]].z-=c[e[i].bh];
							//cout<<"* "<<e[d[e[i].bh][j]].x<<" "<<e[d[e[i].bh][j]].y<<" "<<e[d[e[i].bh][j]].z<<endl;
						}
					}
					sort(e+i+2,e+cnt+1,cmp);
					vis[e[i].bh]=1;
				}
				
				
			}
			//cout<<ans<<endl;
		}
		if(tot==dot-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
  n_____n
 / o   o \ 
 \+  u  +/ 
 / v   v \
样例在这里~
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4

100 1 3 2 4
*/

