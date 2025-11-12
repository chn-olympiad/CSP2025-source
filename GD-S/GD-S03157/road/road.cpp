#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fir[10010],to[1000010],nxt[1000010],w[1000010],s;
void li(int x,int y,int f){
	s++;
	nxt[s]=fir[x];
	fir[x]=s;
	to[s]=y;
	w[s]=f;
}
bool book[10010];
long long ans;
void mk(int x){
	int sum=1;
	book[1]=1;
	while(sum<=n){
		int minn=1e7;
//		cout<<endl<<x<<endl;
		for(int i=fir[x];i;i=nxt[i]){
			int v=to[i];
//			cout<<v<<" ";
			if(!book[v]&&v!=0)
				if(minn>w[i])
					x=v,minn=w[i];
		}
		book[x]=1;
		sum++;
		if(sum==n)
			break;
		ans+=minn;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,f;
		scanf("%d%d%d",&u,&v,&f);
		li(u,v,f);
		li(v,u,f);
	}
	mk(1);
	cout<<ans;
	return 0;
}
/*
4 6 0
1 2 1
1 3 100
1 4 100
2 3 1
2 4 1
3 4 1000
*/

