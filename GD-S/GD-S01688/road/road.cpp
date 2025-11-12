#include<bits/stdc++.h>
using namespace std;

struct node{
	int fa,val;
};

struct egg{
	long long w;
	int u,v;
};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	vector<egg> edge;
	
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		edge.push_back({w,u,v});
	} 
	
	sort(edge.begin(),edge.end(),[](egg x,egg y){
		return x.w < y.w;
	});
	
	vector<vector<int>> cv(k+5,vector<int>(n+5));
	vector<long long> vlg(k+5);
	int vlgcst,ctTvlC;
	for(int i=0;i<k;i++){
		scanf("%d",&vlgcst);
		vlg[i] = vlgcst;
		for(int j=1;j<=n;j++){
			scanf("%d",&ctTvlC);
			cv[i][j] = ctTvlC;
		}
	}
	
	vector<node> bcj(n+20);
	
	auto fnd = [&](auto fnd,int x)->int{
		if(bcj[x].fa == x) return x;
		int f = fnd(fnd,bcj[x].fa);
		bcj[f].val += bcj[x].val;
		bcj[x].val = 0;
		bcj[x].fa = f;
		return f;
	};
	
	auto ins = [&](int x,int y) {
		int fx = fnd(fnd,x);
		int fy = fnd(fnd,y);
		bcj[fx].fa = fy;	
		bcj[fy].val += bcj[fx].val;
		bcj[fx].val = 0;
	};
	
	auto get = [&](int st){
		for(int i=0;i<=n+15;i++){
			bcj[i].fa = i;
			bcj[i].val = 1;
		}
		vector<egg> vged;
		int num = n + __builtin_popcount(st);
		long long cst = 0;
		for(int stp=st;stp;stp&=stp-1){
			int p = __builtin_ctz(stp);
			cst += vlg[p];
			for(int i=1;i<=n;i++){
				vged.push_back({cv[p][i],p+n+2,i});
			}
		}
		
		sort(vged.begin(),vged.end(),[](egg x,egg y){
			return x.w < y.w;
		});
		int sz = vged.size();
		
		int i=0,j=0;
		for(;i<m or j<sz;){
			if(j>=sz or (i<m and edge[i].w < vged[j].w)){
				int x = edge[i].u;
				int y = edge[i].v;
				if(fnd(fnd,x) == fnd(fnd,y)){
					i++;
					continue;
				}
				ins(x,y);
				cst += edge[i].w;
				i++;
			}
			if(i>=m or (j<sz and edge[i].w >= vged[j].w)){
				int x = vged[j].u;
				int y = vged[j].v;
				if(fnd(fnd,x) == fnd(fnd,y)){
					j++;
					continue;
				}
				ins(x,y);
				cst += vged[j].w;
				j++;
			}
			if(bcj[fnd(fnd,1)].val==num){
				break;
			}
			if(i>=m and j>=sz) return 1ll*10000000000;
		}
		
		return cst;
	};
	
	long long ans = 1e10;
	for(int st=0;st<(1<<k);st++){
		ans = min(ans,get(st));
	}
	
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
