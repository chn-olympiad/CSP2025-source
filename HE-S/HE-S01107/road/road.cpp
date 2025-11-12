#include<bits/stdc++.h>
using namespace std;

int n,m,k,nk,ecnt;
long long ans,good_ans=90000000000000000ll;
struct edge{
	int u,v,w;
}E[2000005];
int c[15],f[15][10005];
void add(int u,int v,int w){
	E[++ecnt].u=u;E[ecnt].v=v;E[ecnt].w=w;
}
int father[10005];
int root(int now){
	return father[now]==now?now:father[now]=root(father[now]);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;nk=n+k;
	for(int i=1;i<=nk;i++){
		father[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	int ok=1;
	for(int i=1;i<=k;i++){
		if(c[i]) ok=0;
	}
	if(ok){
		if(k==0){
			add(0,1,0);
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				add(j,n+i,f[i][j]);
			}
		}
		sort(E+1,E+ecnt+1,cmp);
		for(int i=1;i<=ecnt;i++){
			int u=E[i].u,v=E[i].v,w=E[i].w;
			int a=root(u),b=root(v);
			if(a!=b){
				father[a]=b;
				ans+=w;
			}
		}
		cout<<ans;
	}else{
		int huilai=ecnt,ii;
		for(int i=1;i<=30;i++){
			ans=0;ecnt=huilai;
			for(int j=1;j<=nk;j++){
				father[j]=j;
			}
			if(2<=i&&i<=6){
				ans+=c[i-1];
				for(int j=1;j<=n;j++){
					add(j,n+i-1,f[i-1][j]);
				}
			}else if(i==7){
				for(int ii=1;ii<=2;ii++){
					ans+=c[ii];
					for(int j=1;j<=n;j++){
						add(j,n+ii,f[ii][j]);
					}
				}
			}else if(i==8){
				ii=1;
				ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==9){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==10){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==11){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==12){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==13){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==13){
				ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==14){
				ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==15){
				ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==16){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==17){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==18){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==19){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==20){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==21){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==22){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==23){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==24){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==25){
				ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==26){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==27){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==28){
				ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==29){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}else if(i==30){
				ii=2;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=3;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=4;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=5;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}ii=1;ans+=c[ii];
				for(int j=1;j<=n;j++){
					add(j,n+ii,f[ii][j]);
				}
			}
			sort(E+1,E+ecnt+1,cmp);
			for(int j=1;j<=ecnt;j++){
				int u=E[j].u,v=E[j].v,w=E[j].w;
				int a=root(u),b=root(v);
				if(a!=b){
					father[a]=b;
					ans+=w;
				}
			}
			good_ans=min(good_ans,ans);
		}
		cout<<good_ans;
	}
	return 0;
}
