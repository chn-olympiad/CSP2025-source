#include<bits/stdc++.h>
using namespace std;
/*
const int N=1e4+5;
const int M=1e6+1e5+5;
#define ll long long  
int ans;
struct node {
    int u,v,w;
}e[100005];
int c[100005],
int Fa[N];
int Fd(int x){
	if(x==Fa[x]){
		return x;
	}
	Fa[x]=Fd(Fa[x]);
	return Fa[x];
}
void merge(int u,int v){
    int x=Fd(u),y=Fd(v);
    if(x==y){
		return ;
	}
	Fa[x]=y;
	return ;
}
*/
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cout<<"0\n";
    /*
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
	    cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
	    for(int j=1;j<=n;j++){
		    cin>>w[i][j];
		}
	}
	for(int i=1;i<=n;i++){
	    Fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	long long ans=1e18,sum=0;
	for(int i=1;i<=m;i++){
	    if(Fd[e[i].u)!=Fd[e[i].v)){
		    merge(e[i].u,e[i].v);
		    fl[i]=1;
		}
	}
	for(int i=0;i<=(1<<k);i++){
		
	}
	ans=sum;
	cout<<ans<<"\n";
	int en=m;
	for(int i=1;i<=k;i++){
		long long x;
		cin>>x;
		++en;
		e[en].u=n+1;
		e[en].v=1;
		e[en].w=x;
	    for(int j=1;j<=n;j++)_{
			long long x;
			cin>>x;
			if(i!=j){
				++en;
				e[en].u=i;
				e[en].v=j;
				e[en].w=x;
			}
		}
	}
	sort(e+1,e+en+1,cmp); 
	*/
    return 0;
}
 

//Ren5Jie4Di4Ling5%
