#include <bits/stdc++.h>

using namespace std;

int g[10005][10005],stl[15],cnt,b[15];
long long n,m,k,ans;
long long a[10005];
struct nc{
	int c;
	int a[10005];
}l[15];
int ans2(int x,int y){
	int cn=0;
	stack<int> st;
	st.push(0);
	int an=INT_MAX;
	for(int i=1;i<=k;i++){
		   int an1=min(l[i].a[x]+l[i].a[y],an);
		   if(an1<an){
		   	  st.pop();
		   	  st.push(i);
		   }
		   an=an1;
	}
	int stn=st.top();
	stl[++cnt]=l[stn].c;
	return an;
}
void unque(){
	int cj=1;
	for(int i=1;i<=15;i++){
		if(stl[i]!=-1){
		b[stl[i]]=1;
	}
	}
	for(int i=1;i<=15;i++){
		if(b[i]!=0){
			stl[cj++]=i;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>l[i].c;
		for(int j=1;j<=n;j++){
			cin>>l[i].a[j];
		}
	}
	for(int i=1;i<=11;i++){
		stl[i]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]){
				int ma;
		       if(ans2(i,j)+l[i].c<=g[i][j]){
		       	   ma=ans2(i,j)+l[i].c;
		       	  l[i].c=0;
			   }else{
			   	   ma=g[i][j];
			   }
		       g[i][j]=0;
		       g[j][i]=0;
		       ans+=ma;
		    }
	    }
	}	unque();
	for(int i=1;stl[i]>=0;i++){
		ans+=stl[i];
	}
	cout<<ans;
	return 0;
}
