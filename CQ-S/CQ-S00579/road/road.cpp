#include<bits/stdc++.h>
using namespace std;
struct b{
	int u,v,w;
}t[110005],ls[1000005];
int f[10005],c[15],zt[15],ts=0;
int cmp(b p1,b p2){
	return p1.w<p2.w;
}
int find(int x){
	if(f[x]==x)
		return x;
	f[x]=find(f[x]);
	return f[x];
}
int read(){
	int x=0;
	char s=getchar();
	while(s<'0'||s>'9')
		s=getchar();
	while(s>='0'&&s<='9'){
		x=x*10+(s-'0');
		s=getchar();
	}
	return x;
}
int main(){
	int n,m,k;
	long long ans=LONG_LONG_MAX;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<m;i++){
		ls[i].u=read();
		ls[i].v=read();
		ls[i].w=read();
	}
	sort(ls,ls+m,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=0;i<m;i++){
		if(find(ls[i].u)!=find(ls[i].v)){
			f[find(ls[i].v)]=find(ls[i].u);
			t[ts].u=ls[i].u;
			t[ts].v=ls[i].v;
			t[ts].w=ls[i].w;
			ts++;
		}
	}
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=0;j<n;j++,ts++){
			t[ts].w=read();
			t[ts].u=i+1+n;
			t[ts].v=j+1;
		}
	}
	sort(t,t+ts,cmp);
	while(1){
		bool cl=1;
		long long jg=0;
		for(int i=0;i<k;i++)
			jg+=c[i]*zt[i];
		for(int i=1;i<=n+k;i++)
			f[i]=i;
		for(int i=0;i<ts;i++){
			if(find(t[i].u)!=find(t[i].v)){
				if(t[i].u>n){
					if(zt[t[i].u-n-1]){
						f[find(t[i].v)]=find(t[i].u);
						jg+=t[i].w;
					}
				}else{
					f[find(t[i].v)]=find(t[i].u);
					jg+=t[i].w;
				}
			}
		}
		ans=min(ans,jg);
		for(int i=0;i<k;i++){
			if(zt[i]==0){
				zt[i]=1;
				cl=0;
				break;
			}else
				zt[i]=0;
		}
		if(cl)
			break;
	}
	printf("%lld",ans);
	return 0;
}
