#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long all_v=0,del_v=0;
bool b[1024];
struct tt{
	int v,w,g;
	bool is_s;
	tt(int b,int c,int d,bool e){
		v=b;
		w=c,g=d;
		is_s=e;
	}
	bool operator <(const tt &A){
		return w<A.w;
	}
};
vector<tt> edge[1024];
inline void dfs(int x){
	b[x]=true;
	for(int i=0;i<edge[x].size();i++){
		int y=edge[x][i].v;
		if(!b[y])
			dfs(b[y]);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		edge[uu].push_back(tt(vv,ww,-1,false));
		edge[vv].push_back(tt(uu,ww,-1,false));
		all_v+=ww;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			edge[i+n].push_back(tt(j,x,c,false));
			edge[j].push_back(tt(i+n,x,c,false));
			all_v+=x;
		}
	}
	memset(b,false,sizeof(b));
	for(int i=1;i<=n+k;i++){
		sort(edge[i].begin(),edge[i].end());
		//for(int j=0;j<edge[i].size();j++)
		//	cout<<edge[i][j].w<<" ";
		//cout<<"\n";
		if(edge[i].size()&&i>n){edge[i][0].w+=edge[i][0].g;}
		if(edge[i].size()>1){
			if(i>n){
				edge[i][0].w+=edge[i][0].g;
			}
			sort(edge[i].begin(),edge[i].end());
			while(edge[i].size()>1){
				del_v+=edge[i][1].w;
				edge[i].erase(edge[i].begin()+2);
			}
		}
		//for(int j=0;j<edge[i].size();j++)
			//cout<<edge[i][j].w<<" ";
		//cout<<"\n";
	}
	//dfs(1);
	//for(int i=1;i<=n+k;i++){
	//	if(!b[i])
	//		cout<<"No\n";
	//}
	cout<<all_v-del_v;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
