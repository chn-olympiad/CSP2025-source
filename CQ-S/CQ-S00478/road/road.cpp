#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,cnt;
struct node{
	int x,y,z;
} e[1000005],e1[10005];
bool cmp(node e1,node e2){
	return e1.z<e2.z; 
}
int baba[10005];
int getbaba(int x){
	if(x==baba[x]) return x;
	return baba[x]=getbaba(baba[x]);
}
int c[15],a[15][1005],su[15];
bool v[15];
int vv[15][1005];
int vv1[15][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) baba[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(e+1,e+1+m,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			int ba1=getbaba(e[i].x);
			int ba2=getbaba(e[i].y);
			if(ba1==ba2) continue;
			baba[ba1]=ba2;
			ans+=e[i].z;
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=m;i++){
		int fa1=getbaba(e[i].x);
		int fa2=getbaba(e[i].y);
		if(fa1==fa2) continue;
		ans+=e[i].z;
		e1[++cnt]=e[i];
		baba[fa1]=fa2;
		for(int j=1;j<=1;j++){
			if(vv[j][e[i].x]>0&&vv[j][e[i].y]>0)
				su[j]+=e[i].z;
			else if(vv[j][e[i].x]>0){
				int ss=a[j][e[i].y]+a[j][vv1[j][e[i].x]];
				if(e[i].z>e[vv[j][e[i].x]].z){
					ss=e[i].z-ss;
					if(ss<0) continue;
					su[j]+=ss;
					vv[j][e[i].y]=i;
					vv[j][vv1[j][e[i].x]]=i;
					vv[j][e[i].x]=0;
					vv1[j][e[i].y]=vv1[j][e[i].x];
					vv1[j][vv1[j][e[i].x]]=e[i].y;
					vv1[j][e[i].x]=0;
				}else{
					ss=e[vv[j][e[i].x]].z-ss;
					if(ss<0) continue;
					su[j]+=ss;
					vv[j][e[i].y]=vv[j][e[i].x];
					vv[j][e[i].x]=0;
					vv1[j][e[i].y]=vv1[j][e[i].x];
					vv1[j][vv1[j][e[i].x]]=e[i].y;
					vv1[j][e[i].x]=0;
				}
 			}else if(vv[j][e[i].y]>0){
 				int ss=a[j][e[i].x]+a[j][vv1[j][e[i].y]];
				if(e[i].z>e[vv[j][e[i].y]].z){
					ss=e[i].z-ss;
					if(ss<0) continue;
					su[j]+=ss;
					vv[j][e[i].x]=i;
					vv[j][vv1[j][e[i].y]]=i;
					vv[j][e[i].y]=0;
					vv1[j][e[i].x]=vv1[j][e[i].y];
					vv1[j][vv1[j][e[i].y]]=e[i].x;
					vv1[j][e[i].y]=0;
				}else{
					ss=e[vv[j][e[i].y]].z-ss;
					if(ss<0) continue;
					su[j]+=ss;
					vv[j][e[i].x]=vv[j][e[i].y];
					vv[j][e[i].y]=0;
					vv1[j][e[i].x]=vv1[j][e[i].y];
					vv1[j][vv1[j][e[i].y]]=e[i].x;
					vv1[j][e[i].y]=0;
				}
			}else{
				int ss=a[j][e[i].x]+a[j][e[i].y];
				su[j]+=max(e[i].z-ss,0ll);
				vv[j][e[i].x]=i;
				vv[j][e[i].y]=i;
				vv1[j][e[i].x]=e[i].y;
				vv1[j][e[i].y]=e[i].x;
			}
		}
	}int p=0,ma=0;
	for(int i=1;i<=k;i++){
		su[i]-=c[i];
		if(su[i]>=ma){
			p=i;
			ma=su[i]; 
		}
	}while(su[p]>0){
		v[p]=true; ans-=su[p];
		for(int i=1;i<=cnt;i++)
			if(e1[i].z>a[p][e1[i].x]+a[p][e1[i].y])
				e1[i].z=a[p][e1[i].x]+a[p][e1[i].y];
		for(int i=1;i<=k;i++){
			su[i]=0;
			for(int j=1;j<=n;j++) vv[i][j]=0;
		}
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=k;j++){
				if(vv[j][e1[i].x]&&vv[j][e1[i].y])
					su[j]+=e1[i].z;
				else if(vv[j][e1[i].x]){
					int ss=a[j][e1[i].y]+a[j][vv1[j][e1[i].x]];
					if(e1[i].z>e1[vv[j][e1[i].x]].z){
						ss=e1[i].z-ss;
						if(ss<0) continue;
						su[j]+=ss;
						vv[j][e1[i].y]=i;
						vv[j][vv1[j][e1[i].x]]=i;
						vv[j][e1[i].x]=0;
						vv1[j][e1[i].y]=vv1[j][e1[i].x];
						vv1[j][vv1[j][e1[i].x]]=e1[i].y;
						vv1[j][e1[i].x]=0;
					}else{
						ss=e1[vv[j][e1[i].x]].z-ss;
						if(ss<0) continue;
						su[j]+=ss;
						vv[j][e1[i].y]=vv[j][e1[i].x];
						vv[j][e1[i].x]=0;
						vv1[j][e1[i].y]=vv1[j][e1[i].x];
						vv1[j][vv1[j][e1[i].x]]=e1[i].y;
						vv1[j][e1[i].x]=0;
					}
	 			}else if(vv[j][e1[i].y]){
	 				int ss=a[j][e1[i].x]+a[j][vv1[j][e1[i].y]];
					if(e1[i].z>e1[vv[j][e1[i].y]].z){
						ss=e1[i].z-ss;
						if(ss<0) continue;
						su[j]+=ss;
						vv[j][e1[i].x]=i;
						vv[j][vv1[j][e1[i].y]]=i;
						vv[j][e1[i].y]=0;
						vv1[j][e1[i].x]=vv1[j][e1[i].y];
						vv1[j][vv1[j][e1[i].y]]=e1[i].x;
						vv1[j][e1[i].y]=0;
					}else{
						ss=e1[vv[j][e1[i].y]].z-ss;
						if(ss<0) continue;
						su[j]+=ss;
						vv[j][e1[i].x]=vv[j][e1[i].y];
						vv[j][e1[i].y]=0;
						vv1[j][e1[i].x]=vv1[j][e1[i].y];
						vv1[j][vv1[j][e1[i].y]]=e1[i].x;
						vv1[j][e1[i].y]=0;
					}
				}else{
					int ss=a[j][e1[i].x]+a[j][e1[i].y];
					su[j]+=max(e1[i].z-ss,0ll);
					vv[j][e1[i].x]=i;
					vv[j][e1[i].y]=i;
					vv1[j][e1[i].x]=e1[i].y;
					vv1[j][e1[i].y]=e1[i].x;
				}
			}	
		}ma=0,p=0;
		for(int i=1;i<=k;i++){
			if(v[i]) continue;
			su[i]-=c[i];
			if(su[i]>=ma){
				ma=su[i];
				p=i;
			}
		}
	}cout<<ans;
	return 0;
}
