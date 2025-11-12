#include<bits/stdc++.h>
using namespace std;
struct o{
	int u,v;
	long long w;
}l[10000001];
bool cmp(o a,o b){
	return a.w<b.w;
}
long long n,m,k,u[1000001],v[1000001],w[1000001],f[10001],z,ans,s,p[11][10001],xxx[11],fl,b[12];
int ff(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=ff(f[x]);
	return f[x];
}
void merge(int x,int y){
	int a=ff(x),b=ff(y);
	f[a]=b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		l[i].u=u[i];
		l[i].v=v[i];
		l[i].w=w[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>xxx[i];
		if(xxx[i]){
			fl=1;
		}
		int fr=0;
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			if(!p[i][j]){
				fr=1;
			}
		}
		if(!fr){
			fl=1;
		}
	}
	sort(l+1,l+m+1,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			if(ff(l[i].u)==ff(l[i].v)){
				continue;
			}
			ans+=l[i].w;
			merge(l[i].u,l[i].v);
		}
		cout<<ans;
	}
	else if(!fl){
		for(int i=1;i<=k;i++){
			int x;
			for(int j=1;j<=n;j++){
				if(!p[i][j]){
					x=j;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				z++;
				l[m+z].u=x;
				l[m+z].v=j;
				l[m+z].w=p[i][j];
			}
		}
		sort(l+1,l+m+z+1,cmp);
		for(int i=1;i<=m+z;i++){
			if(ff(l[i].u)==ff(l[i].v)){
				continue;
			}
			ans+=l[i].w;
			merge(l[i].u,l[i].v);
		}
		cout<<ans;
	}
	else{
		ans=99999999999999999;
		int xt=0,vp=pow(2,k);
		while(xt<vp){
			xt++;
			s=z=0;
			for(int i=1;i<=k;i++){
				if(!b[i]){
					continue;
				}
				s+=xxx[i];
				for(int j=2;j<=n;j++){
					for(int g=1;g<j;g++){
						z++;
						l[m+z].u=j;
						l[m+z].v=g;
						l[m+z].w=p[i][j]+p[i][g]; 
					}
				}
			} 
			sort(l+1,l+m+z+1,cmp);
			for(int i=1;i<=m+z;i++){
				if(ff(l[i].u)==ff(l[i].v)){
					continue;
				}
				s+=l[i].w;
				if(s>=ans){
					break;
				}
				merge(l[i].u,l[i].v);
			}
			ans=min(ans,s);
			for(int i=1;i<=n;i++){
				f[i]=i;
			}
			for(int i=1;i<=m;i++){
				l[i].u=u[i];
				l[i].v=v[i];
				l[i].w=w[i];
			}
			b[1]++;
			for(int i=1;i<=k;i++){
				if(b[i]==2){
					b[i]=0;
					b[i+1]++;
				} 
			} 
		}
		cout<<ans;
	}
	return 0;
} 
