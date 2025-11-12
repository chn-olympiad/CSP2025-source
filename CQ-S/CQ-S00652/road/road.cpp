//road
#define gf getfather
#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
using namespace std;
// namespace _746969_{
	int a[20][1010],sz[1010],u[1000010],v[1000010],w[1000010],fa[1010],id[1000010];
	long long ans=LLONG_MAX,t3;
	struct Node{
		int u,v,w;
		bool operator<(const Node &other)const{
			return w<other.w;
		}
	}edge[1010010];
	int getfather(const int &x){
		if(fa[x]==x)
			return x;
		return fa[x]=getfather(fa[x]);
	}
	// signed main(){
	// 	int n,m,k,t1,t2,rnt,t,c[20];
	// 	cin>>n>>m>>k;
	// 	for(int i=1;i<=m;i++)
	// 		cin>>u[id[i]=i]>>v[i]>>w[i];
	// 	stable_sort(id+1,id+1+m,[](int x,int y){return w[x]<w[y];});
	// 	for(int i=1;i<=k;i++){
	// 		cin>>c[i];
	// 		for(int j=1;j<=n;j++)
	// 			cin>>a[i][j];
	// 	}
	// 	int tot=1<<k;
	// 	for(int plan=0;plan<tot;plan++){
	// 		t3=rnt=0;
	// 		for(int i=1;i<=m;i++)
	// 			edge[++rnt]={u[id[i]],v[id[i]],w[id[i]]};
	// 		for(int i=1;i<=n;i++)
	// 			fa[i]=i,sz[i]=1;
	// 		for(int i=1;i<=k;i++){
	// 			if(!(plan&(1<<(i-1))))
	// 				continue;
	// 			t3+=c[i];
	// 			for(int j=1;j<=n;j++){
	// 				t1=n+i;
	// 				sz[fa[t1]=t1]=1;
	// 				edge[++rnt]={t1,j,a[i][j]};
	// 			}
	// 		}
	// 		stable_sort(edge+1,edge+1+rnt);
	// 		for(int i=1;i<=rnt;i++){
	// 			t1=gf(edge[i].u);
	// 			t2=gf(edge[i].v);
	// 			if(t1==t2)
	// 				continue;
	// 			if(sz[t1]<sz[t2]){
	// 				t=t1;
	// 				t1=t2;
	// 				t2=t;
	// 			}
	// 			fa[t2]=t1;
	// 			if(t3>=ans)
	// 				break;
	// 			sz[t1]+=sz[t2];
	// 			t3+=edge[i].w;
	// 			t1=gf(n);
	// 			for(int j=1;j<n;j++)
	// 				if(t1!=gf(j)){
	// 					t1=-1;
	// 					break;
	// 				}
	// 			if(t1+1)
	// 				break;
	// 		}
	// 		ans=ans<t3?ans:t3;
	// 	}
	// 	cout<<ans;
	// 	return 0;
	// }
// };
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,t1,t2,rnt,t,c[20];
	Node *at[15]={edge+1};
	char num;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[id[i]=i]>>v[i]>>w[i];
	stable_sort(id+1,id+1+m,[](int x,int y){return w[x]<w[y];});
	for(int i=1;i<=k;i++){
		cin>>c[i];
		at[i]=at[i-1]+n;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	int tot=1<<k;
	for(register short plan=0;plan<tot;plan++){
		num=t3=rnt=0;
		for(int i=1;i<=m;i++)
			edge[++rnt]={u[id[i]],v[id[i]],w[id[i]]};
		for(int i=1;i<=n;i++)
			sz[fa[i]=i]=1;
		for(char i=1;i<=k;i++){
			if(!(plan&(1<<(i-1))))
				continue;
			++num;
			t3+=c[i];
			for(int j=1;j<=n;j++){
				t1=n+i;
				sz[fa[t1]=t1]=1;
				edge[++rnt]={t1,j,a[i][j]};
			}
		}
		if(t3>=ans)
			continue;
		stable_sort(at[0],at[num]);
		for(register int i=1;i<=rnt;i++){
			t1=gf(edge[i].u);
			t2=gf(edge[i].v);
			if(t1==t2)
				continue;
			if(t1>n||t2>n)
				fa[t2]=t1;
			else{
				if(sz[t1]<sz[t2]){
					t=t1;
					t1=t2;
					t2=t;
				}
				fa[t2]=t1;
				sz[t1]+=sz[t2];
			}
			t3+=edge[i].w;
			if(t3>=ans)
				break;
			if(sz[(t1!=1&&t2!=1)?fa[1]:gf(1)]==n)
				break;
		}
		ans=ans<t3?ans:t3;
	}
	cout<<ans;
	return 0;
	// return _746969_::main();
}