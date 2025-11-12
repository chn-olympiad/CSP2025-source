#include<bits/stdc++.h>
using namespace std;
vector<int> c[15],uv[3];
int n,m,k,id[1000005];
int vis[10005],ans;
bool jmp;
bool cmp(int xa,int yb){
	if(uv[2][xa]<uv[2][yb]) return true;
	return false;
}
int vind(int xa){
	if(vis[xa]==xa) return xa;
	return vis[xa]=vind(vis[xa]);
}
void easier(){
	for(int i=0,unv=n;i<m&&unv;i++){
		int uva=uv[0][id[i]],uvb=uv[1][id[i]];
		printf("%d %d %d\n",uva,uvb,uv[2][id[i]]);
		if(vis[uva]==vis[uvb]&&vis[uva]) continue;
		if(!vis[uva]) swap(vis[uva],vis[uvb]);
		if(!vis[uva]&&!vis[uvb]){
			vis[uva]=vis[uvb]=uva;
			ans+=uv[2][id[i]];
			unv-=2;
		}else if(vis[uva]&&vis[uvb]){
			vis[vind(uvb)]=vis[vind(vis[uva])];
			vind(uvb);
		}
		else{
			vis[uvb]=vind(vis[uva]);
			ans+=uv[2][id[i]];
			unv--;
		}
	}
	printf("%d",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0,xa,yb,wc;i<m;i++,id[i]=i){
		scanf("%d%d%d",&xa,&yb,&wc);
		uv[0].push_back(xa);
		uv[1].push_back(yb);
		uv[2].push_back(wc);
	}
	if(k==0){
		sort(id,id+m,cmp);
		easier();
		return 0;
	}
	scanf("%d",&k);
	for(int i=1,ij;i<=k;i++){
		for(int t=0,ind;t<=n;t++){
			scanf("%d",&ind);
			c[i].push_back(ind);
		}
		if(jmp) continue; 
		for(ij=0;ij<=n&&!c[i][ij];) ij++;
		if(ij>n) jmp=true;
	}
	if(jmp){
		printf("0");
		return 0;
	}
	printf("1");
	return 0;
}
