#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[1000010];
int c[11][10100];
int f[1000010];
int findd(int x){
	if(f[x]==x) return x;
	else return f[x]=findd(f[x]);
}
void ll(int x,int y){
	f[x]=f[findd(y)];
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int d[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}	
	int last=0;
	for(int i=1;i<=k;i++){
	 last=0;
	  for(int j=1;j<=n;j++){
	  	if(d[i]==0&&c[i][j]==0&&last==0){
	  		last=i;
		  }else if(d[i]==0&&c[i][j]==0&&last!=0){
		  	ll(last,i);
		  	last=i;
		  }
	  }
}
	int mi1=999999,mi2=999999,mix,dxb,xxb;
	  for(int i=1;i<=n;i++){
	  	if(f[i]==i){
	  		for(int j=1;j<=m;j++){
	  			if(a[j].u==i||a[j].v==i){
	  				if(a[j].w<mi1){
	  					mi1=a[j].w;
	  				if(a[j].u==i) mix=a[j].u;
	  				else mix=a[j].v;
	  				dxb=j;
					  }
				  }
			  }
			  for(int l=1;l<=k;l++){
		  	if(d[l]+c[l][i]<mi2){
		  		mi2=d[l]+c[l][i];
		  		mix=last;
		  		xxb=l;
			  }
		  }
		  if(mi1<=mi2){
          a[dxb].w=INT_MAX;
		  }else{
          c[xxb][i]=INT_MAX;
		  }
		  ans+=min(mi1,mi2);
		  ll(i,mix);
		  } 
	  }
	 cout<<ans;
	 return 0;
	}
