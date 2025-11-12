#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo k,l,n,m,mm,r,s,ss=1e18,a[1000001],o,b[11],c[11];
lo fa[200011];
struct node{
	lo v,u,w;
}e[1010001];
bool cmp(node x,node y){
	return x.w<y.w;
}
lo father(lo x){
	//cout<<x<<" wants to know its father,his father is "<<fa[x]<<".\n";
	//Sleep(1000);
	if(fa[x]!=x)fa[x]=father(fa[x]);
	else return x;
	return fa[x];
}
void in(lo x,lo y){
	//cout<<x<<" and "<<y<<" wants...\n";
	fa[father(x)]=father(y);
}
lo kru(lo p){
	lo ii,jj,t=0,ans=0;
	for(ii=1;ii<=o;ii++){
		
		if(father(e[ii].v)==father(e[ii].u))continue;
		if(e[ii].u>n&&c[e[ii].u-n]==0)continue;
		//cout<<"ok";
		if(t==p-1)break;
		ans+=e[ii].w;
		in(e[ii].v,e[ii].u);
		//cout<<"ok";
		t++;
	}
	//cout<<ans<<"\n";
	if(t<p-1)return -1;
	return ans;
}
int main(){
	lo i,j,p,q;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&l,&r,&mm);
		o++;
		e[o].v=l,e[o].u=r,e[o].w=mm;
	}
	for(i=1;i<=k;i++){
		scanf("%lld",&b[i]);
		for(j=1;j<=n;j++){
			scanf("%lld",&mm);
			o++;
			e[o].v=j,e[o].u=i+n,e[o].w=mm;	
		}
	}
	sort(e+1,e+o+1,cmp);
	for(i=0;i<(1<<k);i++){
		s=0;
		p=n;
		//cout<<i<<"\n";
		for(j=1;j<=n+k;j++)fa[j]=j;
		for(j=1;j<=k;j++){
			c[j]=0;
			if(i&(1<<(j-1)))s+=b[j],c[j]=1,p++;
		}
		//cout<<"******************";
		q=kru(p);
		if(q<0)continue;
		ss=min(q+s,ss);
	}
	printf("%lld",ss);
	return 0;
}

