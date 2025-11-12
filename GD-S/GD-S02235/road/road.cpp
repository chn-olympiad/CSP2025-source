#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e6+100;
long long n,m,k,w[N],a,b,i,j,c,cun[11][N],f[N],ans[N];
long long  yong[M];
long long an,chu[M];
int te;
struct node{
	int a,b,c;
}e[M+10*N];
bool cmp(node n,node m){
	return  n.c<m.c;
}
int gf(int y,int x){
	if(f[x]!=x) return f[x]=gf(y,x);
	return f[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
		f[i]=i;
	}
	te=1;
	for(i=1;i<=k;i++){
		cin>>w[i];
		if(w[i])te=0;
		for(j=1;j<=n;j++){
			cin>>cun[i][j];
			if(cun[i][j]) te=0;
			e[n+i].a=n+1,e[n+i].b=j,e[n+1].c=cun[i][j];
			
		} 
	}
	if(te){
		cout<<0;
		return 0; 
	} 
	sort(e+1,e+1+m,cmp);
	int x,y,tot=0;
	for(i=1;i<=n;i++){
		x=e[i].a,y=e[i].b;
		if(f[x]!=f[y]){
			chu[++tot]=i;
			f[y]=gf(f[x],f[y]);
			ans[0]+=e[i].c;
		}
		
	}
	int no=k;
	an=ans[0];
	for(i=1;i<=k;i++){
		if(w[i]>=an) w[i]=-1,no--;
	}
	int tmp=0;
	for(i=1;i<=n;i++) f[i]=i;
	
	int u;
	for(i=1;i<=k;i++){
		u=i+k;
		if(w[i]>an) continue;
		ans[i]+=w[i];
		for(j=1;j<=tot;j++){
			x=e[chu[j]].a,y=e[chu[j]].b;
			if(e[chu[j]].c>cun[i][x]+cun[i][y]){
				yong[i]++;
				ans[i]+=cun[i][x]+cun[i][y];
			}
			else ans[i]+=e[chu[j]].c;
		}
		if(!yong[i]) ans[i]-=w[i];
		an=min(an,ans[i]);
	}
	cout<<an;
	return 0;
}
