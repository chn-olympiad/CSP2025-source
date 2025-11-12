#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
long long int vis[maxn],f[maxn],ck[11][maxn],cj[11],n,m,k,t,ans;
struct edge{
	int x,y,z;
}e[maxn*30];
bool cmp(edge t1,edge t2){
	return t1.z<t2.z;
}
int findx(int x){
	if(f[x]==x)return x;
	return f[x]=findx(f[x]);
}
bool check(int x,int y){
	int tx=findx(x);
	int ty=findx(y);
	if(tx==ty)return false;
	return true;
}
void h(int x,int y){
	int tx=findx(x);
	int ty=findx(y);
	f[ty]=tx;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int t1,t2,t3;
	for(int i=1;i<=m;i++){
		cin>>t1>>t2>>t3;
		e[i].x=t1;
		e[i].y=t2;
		e[i].z=t3;
	}
	for(int i=1;i<=k;i++){
		cin>>cj[i];
		for(int j=1;j<=n;j++){
			cin>>ck[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int ti=1;ti<=n;ti++){
				if(i!=j){
					m++;
					e[m].x=j;
					e[m].y=ti;
					e[m].z=cj[i]+ck[i][j]+ck[i][ti];
				}
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	int l=0;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	while(1){
		int t=0;
		for(int i=1;i<=m;i++){
			if(vis[i]==0){
				t=i;break;	
			}
		}
		if(t==0)break;
		vis[t]=1;
		int tx=e[t].x,ty=e[t].y;
		if(check(tx,ty)){
			h(tx,ty);
			l++;
			ans+=e[t].z;
		}
	}
//	sort(xl+1,xl+l+1,cmp);
	
	cout<<ans;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
