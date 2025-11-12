//GZ-S00626 贵阳市第一中学 赵思翰
 #include<bits/stdc++.h>
using namespace std;
int n,m,k,g[10005][10005],ans=0x3f,v[10005];
struct abc{
	int jw=0,jv[10005];
}jj[15],ifj[15];

bool check(){
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			return false;
		}
	}
	return true;
}

void dfs(int nw,int mo){
	if(check()){
		ans=min(ans,mo);
		return; 
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0&&g[nw][i]!=-1){
			v[i]=1;
			dfs(i,mo+g[nw][i]);
			v[i]=0;
		}
	}
	
			
} 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	memset(g,-1,sizeof(g));
	for(int i=1;i<=k;i++){
		ifj[i].jw=0;
		for(int j=1;j<=n;j++){
			ifj[i].jv[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		g[uu][vv]=ww;
		g[vv][uu]=ww;
	}
	for(int i=1;i<=k;i++){
		cin>>jj[i].jw;
		for(int j=1;j<=n;j++){
			cin>>jj[i].jv[j];
		}
	}
	v[1]=1;
	dfs(1,0);
	cout<<ans;
	
	return 0;
}
