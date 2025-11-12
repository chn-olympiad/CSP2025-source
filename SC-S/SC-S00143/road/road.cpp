#include<bits/stdc++.h>
using namespace std;

int n,m,k,u,v,w,a[10020][10020],c[20],e[10020],b[20],ans,t,g;

void f(int x){
	if(x==g){
		e[g]=1;
		if(g>m){
			ans=c[g-m];
		}
	}
	cout<<x<<' '<<ans<<endl;
	int mx=INT_MAX;
	bool flag=0;
	for(int i=1;i<=m;i++){
		if(e[i]==0) flag=1;
	}
	if(flag==0) return;
	flag=0;
	for(int i=1;i<=m+k;i++){
		if(i==x) continue;
		if(e[i]==0&&a[i][x]!=-1){
			e[i]=1;
			ans+=a[i][x];
			if(i>m&&b[i-m]==0){
				ans+=c[i-m];
				b[i-m]=1;
				flag=1;
			}
			f(i);
			mx=min(mx,ans);
			ans-=c[i-m];
			ans-=a[i][x];
			
			if(flag) b[i-m]=0;
			flag=0;
			e[i]=0;
		}
	}
	if(mx!=INT_MAX){
		ans=mx;
	}

	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+k;i++){
		for(int j=1;j<=m+k;j++){
			a[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[i+m][j];
			a[j][i+m]=a[i+m][j];
		}
	}
	w=INT_MAX;
	for(g=1;g<=m+k;g++){
		ans=0;
		for(int j=1;j<=m+k;j++) e[j]=0;
		e[g]=1;
		if(g>m){
			ans=c[g-m];
			b[g-m]=1;
		}
		f(g);
		w=min(w,ans);
	}
	cout<<w;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 