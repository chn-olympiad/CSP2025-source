#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans;
map<int,vector<int> >x,y;
int c[17];
int a[17][10007];
int op[17][10007];
int f[10007],g[10007],h[10007];
bool vis[10007];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=1e12+7;
	}
	//cout<<'?';
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		x[u].push_back(v);
		y[u].push_back(w);
		x[v].push_back(u);
		y[v].push_back(w);
	}
	//cout<<'?';
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	//cout<<'?';
	f[1]=0;
	g[1]=0;
	f[0]=1e9+7;
	for(int i=1;i<=n;i++){
		int num=0;
		//for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
		//cout<<endl;
		for(int j=1;j<=n;j++){
			//cout<<'?';
			if(vis[j])continue;
			if(f[j]<f[num])num=j;
			//cout<<j<<' '<<num<<' ';
		}
		//cout<<endl<<f[num]<<endl;
		ans+=f[num];
		vis[num]=1;
		if(g[num]!=0){
			for(int j=1;j<=n;j++){
				if(vis[j])continue;
				if(a[g[num]][j]*(1-op[g[num]][j])+a[g[num]][h[num]]*(1-op[g[num]][h[num]])+c[g[num]]*(1-op[g[num]][0])<=f[j]){
					f[j]=a[g[num]][j]*(1-op[g[num]][j])+a[g[num]][h[num]]*(1-op[g[num]][h[num]])+c[g[num]]*(1-op[g[num]][0]);
					g[j]=0;
					h[j]=num;
				}
			}
			op[g[num]][0]=1;
			op[g[num]][num]=1;
			op[g[num]][h[num]]=1;
		}
		//for(int i=1;i<=n;i++)cout<<f[i]<<' ';
		//cout<<endl;
		//for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
		//cout<<endl;
		for(int j=0;j<x[num].size();j++){
			int q=x[num][j];
			if(y[num][j]<f[q]){
				//cout<<'A';
				f[q]=y[num][j];
				g[q]=0;
				h[q]=0;
			}
		}
		for(int j=1;j<=k;j++){
			for(int q=1;q<=n;q++){
				if(vis[q])continue;
				if(a[j][num]*(1-op[j][num])+a[j][q]*(1-op[j][q])+c[j]*(1-op[j][0])<=f[q]){
					//cout<<'B';
					f[q]=a[j][num]*(1-op[j][num])+a[j][q]*(1-op[j][q])+c[j]*(1-op[j][0]);
					g[q]=j;
					h[q]=num;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	//system("fc club.out ans.out");
	return 0;
}
