#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,s[21000],f[21000],x[21000],y[21000],vis[2000];
struct data{
	long long a,b,c;
}v[50000000];
bool cmp(data x,data y){
	return x.c<y.c;
}
int find(long long k){
	if(s[k]==k)return k;
	return s[k]=find(s[k]);
}
long long solve(){
	long long l=0,ans=0;
	for(int i=1;i<=n+k;i++)s[i]=i;
	for(int i=1;i<=t;i++){
		if(l==n)break;
		if(find(v[i].a)!=find(v[i].b)){
			s[find(v[i].a)]=find(v[i].b);
			ans+=v[i].c;
			if(v[i].a<=n && vis[v[i].a]==0){l++;vis[v[i].a]=1;}
			if(v[i].b<=n && vis[v[i].b]==0){l++;vis[v[i].b]=1;}
			if(vis[v[i].a]==0 && v[i].a>n){
				for(int j=x[v[i].a];j<=y[v[i].a];j++)
					v[j].c-=f[v[i].a-n];
				stable_sort(v+1,v+t+1,cmp);
				vis[v[i].a]=1;
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i].a>>v[i].b>>v[i].c;
	}
	long long r=m;
	for(int i=1;i<=k;i++){
		cin>>f[i];
		for(int j=1;j<=n;j++){
			long long l;
			cin>>l;
			v[j+m+(i-1)*n].a=i+n;
			v[j+m+(i-1)*n].b=j;
			v[j+m+(i-1)*n].c=l+f[i];
		}
		x[i+n]=r+1;
		y[i+n]=m+n*i;
		r=y[i+n];
	}
	t=m+k*n;
	stable_sort(v+1,v+t+1,cmp);
	cout<<solve();
	return 0;
}
