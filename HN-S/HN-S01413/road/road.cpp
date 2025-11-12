#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],cw[N],cs[N],n,m,k,ans;
vector<int> t[N];
struct Node{
	int u,v,w,op=0;
}b[N];

int find(int i){
	if(a[i]==i)return i;
	else return a[i]=find(a[i]);
}
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cs[0]=1;
	for(int i=1;i<=N;i++)a[i]=i;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
	
	for(int i=1;i<=k;i++){
		int q,p;cin>>q;
		cw[i]=q;
		for(int j=1;j<=n;j++){
			cin>>p;
			if(q==0){
				m++;b[m].u=i;b[m].v=j;
				b[m].w=p+q;
			}
		}
	}sort(b+1,b+1+m,cmp);
	
	int q=n;
	for(int i=1;i<=m;i++){
		if(!q)break;
		if(find(b[i].u)!=find(b[i].v)){
			a[find(b[i].u)]=find(b[i].v);
			ans+=b[i].w;
		}q--;
	}
	cout<<ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
