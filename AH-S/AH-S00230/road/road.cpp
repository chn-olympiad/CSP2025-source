#include<bits/stdc++.h>
using namespace std;
struct str{
	int u,v;
};
int n,m,k,x,y,t,c[15],a[15][10000];
long long sum,s;
int w[1000][1000];
bool f,ff[10000][10000];
bool cmp(str x,str y){
	return w[x.u][x.v]<w[y.u][y.v];
}
int main(){
    freopen("road.in","r",stdin);
	freopen("roaf.out","w",stdout);
	cin>>n>>m>>k; 
	 if(n<=1000){
		 str p[1000005];
	     for(int i=0;i<m;i++){
		    cin>>x>>y>>t;
			w[x][y]=t;
			w[y][x]=t;
			s+=t;
		}
	    for(int i=0;i<k;i++){
			cin>>c[i];
			if(c[i]) f=1;
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			} 
		}
		if(!f){
			int pp=0;
			for(int l=0;l<k;l++){
			    for(int i=0;i<n;i++){
					for(int j=i+1;j<n;j++){
						if(w[i][j]) w[i][j]=max(w[i][j],a[l][i]+a[l][j]);
						else w[i][j]=a[l][i]+a[l][j];
						w[j][i]=w[i][j];
						p[pp++].u=i;p[pp].v=j;
					}
				}
		    }
		    sort(p,p+pp,cmp);
		    int ppp=0;
		    for(int i=0;ppp<n-1;i++){
				if(ff[p[i].u][p[i].v]) continue;
				sum=sum+w[p[i].u][p[i].v];
				ff[p[i].u][p[i].v]=1;
			}
			cout<<sum;
		}
		else cout<<s;
	}
	if(n>1000){
		for(int i=0;i<m;i++){
			cin>>x>>y>>t;
			sum+=t;
		}
		cout<<sum;
    }
}
