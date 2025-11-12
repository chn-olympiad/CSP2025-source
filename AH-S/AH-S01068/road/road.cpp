#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,a[15][10005],c[15],f[10005],l,t,cnt,p;
struct xxx{long long u,v,w;}x[2000005];
bool cmp(xxx a,xxx b){return a.w<b.w;}
long long fa(long long x){
	//cout<<x<<'\n';
	p++;
	//if(p>=1000)return 0;
	if(f[x]==x)return x;
	return f[x]=fa(f[x]);
}
void to(long long a,long long b){
	a=fa(a);
	b=fa(b);
	if(a!=b)f[a]=b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x[i].u,&x[i].v,&x[i].w);
	}
	l=m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		t=1;
		scanf("%lld",&c[i]);
		ans+=c[i];
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]<=a[i][t])t=j;
		}
		ans+=a[i][t];
		for(int j=1;j<=n;j++){
			if(j!=t){
				l++;
				x[l].u=t;
				x[l].v=j;
				x[l].w=a[i][j];
			}
		}
	}
	stable_sort(x+1,x+l+1,cmp);
	t=1;
	while(cnt!=n-1){
		if(fa(x[t].u)!=fa(x[t].v)){
			ans+=x[t].w;
			to(x[t].u,x[t].v);
			cnt++;
		}
		t++;
		//for(int i=1;i<=n;i++)cout<<f[i]<<' ';
		//cout<<'\n';
		//if(cnt==2)return 0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
