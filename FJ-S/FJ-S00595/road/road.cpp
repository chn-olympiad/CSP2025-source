#include<iostream>
#include<cstring>
using namespace std;
int n,m,k,u[1000000],v[1000000],co[1000000],c[10][10005],city[10005][10005];
bool a=0,froad[1000000],kp[1000000],ckp[10][10005];
int fr(int x,int y,short b){
	int re=2147283647,mi=-1;
	if(b==2) int ret=2147283647;
	for(int i=0;i<m;i++){
		if(u[i]==x&&v[i]==y) return co[i];
		else if(u[i]==x&&froad[i]==0){
			
			froad[i]=1;
			if(re>co[i]+fr(v[i],y,0)) re=fr(v[i],y,0),mi=i;
			if(b==2) if(ret>re) ret=re;
			
		}
	}
	ret=min(ret,co[i]+fr(v[i],y),1);
	if(b==2) 
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(kp,1,sizeof(kp));
	memset(ckp,1,sizeof(ckp));
	for(int i=0;i<m;i++) cin>>u[i]>>v[i]>>co[i];
	for(int i=0;i<k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++) cin>>c[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(city[i][j]==0){
				int max=fr(i,j,2);
				
			}
		}
	}
	return 0;
}
