#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int rans=1e18,zans;
int fa[111111];
int look(int x){
	if(fa[x]==x)return x;
	return fa[x]=look(fa[x]);
}
void mager(int x,int y){
	fa[look(x)]=look(y);
	return ;
}
struct sb{
	int x,y,z;
}zzx[1111111],e[1111111],xin[11][100005],zxin[1111111],gen[2][1111111];
int hua[11];
bool cmp(sb a,sb b){
	return a.z<b.z;
}
bool cmp1(sb a,sb b){
	if(a.x==b.x){
		if(a.y==b.y){
			return a.z<b.z;
		}
		return a.y<b.y;
	}
	return a.x<b.x;
}
void shuru(){
	int jia_m;
	cin>>n>>jia_m>>k;
	for(int i=1;i<=jia_m;i++){
		cin>>zzx[i].x>>zzx[i].y>>zzx[i].z;
	}
	sort(zzx+1,zzx+1+jia_m,cmp1);
	for(int i=1;i<=jia_m;i++){
		if(zzx[i].x==zzx[i-1].x&&zzx[i].y==zzx[i-1].y)continue;
		m++;
		e[m].x=zzx[i].x;
		e[m].y=zzx[i].y;
		e[m].z=zzx[i].z;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>hua[i];
		for(int j=1;j<=n;j++){
			cin>>xin[i][j].z;
			xin[i][j].x=i+n;
			xin[i][j].y=j;
		}
		sort(xin[i]+1,xin[i]+1+n,cmp);
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	return ;
}
int zge[2],ge;

void kankan(){
	int i=1,j=1;
	if(ge==0){
		j=0;
	}
	int x,y,z;
	for(;(i<=m&&((j<=ge)||(ge==0)));){
		if((e[i].z<zxin[j].z)||(j==0)){
			x=e[i].x;y=e[i].y;z=e[i].z;
			i++;
		}
		else{
			x=zxin[j].x;y=zxin[j].y;z=zxin[j].z;
			j++;
		}
//		cout<<x<<" "<<y<<"\n";
		x=look(x);y=look(y);
		if(x==y)continue;
		mager(x,y);
		zans+=z;
		if(zans>rans){
			return ;
		}
	}
	rans=min(rans,zans);
	return ;
}
void qingli(){
	zans=0;
	zge[0]=zge[1]=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	return ;
}
int id=0;
void mixing(int x){
	int i=1,j=1,idd=(id+1)%2;
	zge[idd]=0;
	while(i<=zge[id]&&j<=n){
		zge[idd]++;
		if(gen[id][i].z>xin[x][j].z){
			gen[idd][zge[idd]].x=xin[x][j].x;
			gen[idd][zge[idd]].y=xin[x][j].y;
			gen[idd][zge[idd]].z=xin[x][j].z;
			j++;
		}
		else{
			gen[idd][zge[idd]].x=gen[id][i].x;
			gen[idd][zge[idd]].y=gen[id][i].y;
			gen[idd][zge[idd]].z=gen[id][i].z;
			i++;
		}
	}
	while(i<=zge[id]){
		zge[idd]++;
		gen[idd][zge[idd]].x=gen[id][i].x;
		gen[idd][zge[idd]].y=gen[id][i].y;
		gen[idd][zge[idd]].z=gen[id][i].z;
		i++; 
	}
	while(j<=n){
		zge[idd]++;
		gen[idd][zge[idd]].x=xin[x][j].x;
		gen[idd][zge[idd]].y=xin[x][j].y;
		gen[idd][zge[idd]].z=xin[x][j].z;
		j++;
	}
	id=idd;
	return ;
}
void chuli(int x){
	qingli();
	zge[0]=zge[1]=0;
	id=0;
	zans=0;
	for(int i=1;i<=k;i++){
		if((x&(1<<(i-1)))!=0){
			zans+=hua[i];
			mixing(i);
		}
	}
	if(zans>=rans)return ;
	ge=zge[id];
//	cout<<ge<<"**\n";
	for(int i=1;i<=ge;i++){
		zxin[i].x=gen[id][i].x;
		zxin[i].y=gen[id][i].y;
		zxin[i].z=gen[id][i].z;
//		cout<<zxin[i].x<<" "<<zxin[i].y<<" "<<zxin[i].z<<"\n";
	}
//	cout<<zans<<"\n";
//	cout<<x;
//	sort(zxin+1,zxin+1+zge,cmp);
//	for(int i=1;i<=zge;i++){
//		cout<<zxin[i].x<<" "<<zxin[i].y<<" "<<zxin[i].z<<"\n";
//	}
	kankan();
	return ;
}
int falg[111111];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	shuru();
	for(int i=1;i<=k;i++){
		chuli((1<<k));
		falg[(1<<k)]=1;
	}
	for(int i=0;i<(1<<k);i++){
		if(falg[i]==0)chuli(i);
//		cout<<i<<"\n";
	}
	cout<<rans;
	return 0;
}
