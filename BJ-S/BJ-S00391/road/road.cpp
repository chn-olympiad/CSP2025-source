#include <bits/stdc++.h>
using namespace std;
struct bian{
	int u,v;
	long long w;
	bool friend operator <(bian a,bian b){
		return a.w<b.w;
	}
}l[1000050];
int fa[10050];
long long road[1050][1050];
long long dis[1050];
int zu(int n){
	if(fa[n]==0){
		return n;
	}else{
		return fa[n]=zu(fa[n]);
	}
}
void add(int a,int b){
	fa[zu(a)]=zu(b);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int xs=1;xs<=m;xs++){
			int a,b;
			long long c;
			scanf("%d%d%lld",&a,&b,&c);
			l[xs].u=a;
			l[xs].v=b;
			l[xs].w=c;
		}
		sort(l+1,l+1+m);
		long long ans=0;
		for(int xs=1;xs<=m;xs++){
			if(zu(l[xs].u)!=zu(l[xs].v)){
				add(l[xs].u,l[xs].v);
				ans+=l[xs].w;
			}
		}
		cout<<ans;
	}else{
		memset(road,0x3f,sizeof(road));
		for(int xs=1;xs<=m;xs++){
			int a,b;
			long long c;
			scanf("%d%d%lld",&a,&b,&c);
			road[a][b]=min(road[a][b],c);
			road[b][a]=min(road[b][a],c);
		}
		for(int xs=1;xs<=k;xs++){
			long long c;
			cin>>c;
			for(int xs2=1;xs2<=n;xs2++){
				scanf("%lld",&dis[xs2]);
			}
			for(int xs2=1;xs2<=n;xs2++){
				for(int xs3=1;xs3<=n;xs3++){
					if(xs2!=xs3){
						road[xs2][xs3]=min(road[xs2][xs3],dis[xs2]+dis[xs3]);
					}
				}
			}
		}
		int bnum=0;
		for(int xs=1;xs<=n;xs++){
			for(int xs2=xs+1;xs2<=n;xs2++){
				l[++bnum].w=road[xs][xs2];
				l[bnum].u=xs;
				l[bnum].v=xs2;
			}
		}
		sort(l+1,l+1+bnum);
		long long ans=0;
		for(int xs=1;xs<=m;xs++){
			if(zu(l[xs].u)!=zu(l[xs].v)){
				add(l[xs].u,l[xs].v);
				ans+=l[xs].w;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
