#include<bits/stdc++.h>
using namespace std;
//priority_queue<int> q !!!!!!!!!!!!!
int n,m,k,o[1005],x,y,v,f[1005],ans,qm[1005],jl[1005];
struct hh{
	int to,l;
};
vector<hh> p[1005];
vector<int> h;
/*struct oo{
	int next,to,qm,l;
}q[1000005];*/
queue<int> q;
/*void chao(int x,int y,int g,int gg){
	if(x<=q[y].l){
		cnt++;
		q[cnt].next=y;
		q[cnt].to=p[gg][g].to;
		q[cnt].qm=q[y].qm;
		q[cnt].l=p[gg][g].to;
		if(q[cnt].qm==0) h=cnt;
		q[q[y].qm].next=cnt;
		q[y].qm=cnt;
		return;
	}
	chao(x,q[y].next,g,gg);
}*/
void dfs(int x){
	jl[x]++;
	if(qm[x]==0){
		ans+=f[x];
		return;
	}
	dfs(qm[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>v;
		p[x].push_back(hh{y,v});
		p[y].push_back(hh{x,v});
	}
	for(int i=1;i<=k;i++){
		cin>>v;
		for(int j=1;j<=n;j++){
			cin>>o[j];
			for(int z=1;z<j;z++){
				p[j].push_back(hh{z,v+o[j]+o[z]});
				p[z].push_back(hh{j,v+o[j]+o[z]});
			}
		}
	}
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	//for(int i=1;i<p[1].size();i++) chao(p[1][i],h,i,1);
	q.push(1);
	while(!q.empty()){
		x=q.front();
		q.pop();
		int flag=1;
		for(int i=0;i<p[x].size();i++){
			int xx=p[x][i].to,yy=p[x][i].l;
			if(f[xx]>yy+f[x]){
				qm[xx]=x;
				f[xx]=f[x]+yy;
				flag=0;
				q.push(xx);
			}
		}
		if(flag){
			h.push_back(x);
		}
	}
	//for(int i=1;i<=n;i++) cout<<f[i]<<' ';
	for(int i=0;i<h.size();i++) ans+=f[h[i]];//dfs(h[i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	//我忘了优先队列咋写了，不然我就拿下了！超超超超超！！！！！！！！ 
	return 0;
}//遗憾离场 
