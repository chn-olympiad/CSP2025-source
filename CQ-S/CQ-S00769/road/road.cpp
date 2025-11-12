#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	const int mn=10013,mm=1000003;
	struct edge{
		int x,y,w;
	}e[mm],ee[mn];
	bool operator < (edge a,edge b){
		return a.w<b.w;
	}
	pair<int,int>p[13][mn];
	int f[mn],c[mn],np[13];
	int getf(int x){
		if(f[x]==x)
			return x;
		return f[x]=getf(f[x]);
	}
	int read(){
		int x;
		char c;
		while(1){
			c=getchar();
			if('0'<=c&&c<='9')
				break;
		}
		x=c-'0';
		while(1){
			c=getchar();
			if('0'<=c&&c<='9')
				x=x*10+c-'0';
			else
				break;
		}
		return x;
	}
	int main(){
		int n,m,k,ecnt=0;
		long long ans,now;
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=m;i++){
			e[i].x=read();
			e[i].y=read();
			e[i].w=read();
		}
		sort(e+1,e+1+m);
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++){
				p[i][j].first=read();
				p[i][j].second=j;
			}
			sort(p[i]+1,p[i]+1+n);
		}
		for(int i=1;i<=n;i++)
			f[i]=i;
		ans=0;
		for(int i=1;i<=m;i++)
			if(getf(e[i].x)!=getf(e[i].y)){
				ans+=e[i].w;
				ee[++ecnt]=e[i];
				f[getf(e[i].x)]=getf(e[i].y);
			}
//		cerr<<ans;
		for(int i=0;i<(1<<k);i++){
			for(int j=1;j<=n+k;j++)
				f[j]=j;
			now=0;
			int lft=n-1,ne=1;
			for(int j=1;j<=k;j++){
				if(i&(1<<(j-1))){
					lft++;
					now+=c[j];
				}
				np[j]=1;
			}
			while(lft){
				int sel=-1;
				for(int j=1;j<=k;j++)
					if(i&(1<<(j-1)))
						if(np[j]<=n&&(sel==-1||p[sel][np[sel]].first>p[j][np[j]].first))
							sel=j;
				assert(!(sel==-1&&ne==n));
				if(sel==-1||p[sel][np[sel]].first>=ee[ne].w){
//					cerr<<i<<" "<<ee[ne].x<<"--"<<ee[ne].y<<" "<<ee[ne].w<<endl;
					now+=ee[ne].w;
					f[getf(ee[ne].x)]=getf(ee[ne].y);
					lft--;
				}
				else{
//					cerr<<i<<" "<<n+sel<<"=="<<p[sel][np[sel]].second<<" "<<p[sel][np[sel]].first<<endl;
					now+=p[sel][np[sel]].first;
					f[getf(n+sel)]=getf(p[sel][np[sel]].second);
					lft--;
				}
				while(ne<n&&getf(ee[ne].x)==getf(ee[ne].y))
					ne++;
				for(int j=1;j<=k;j++)
					if(i&(1<<(j-1)))
						while(np[j]<=n&&getf(n+j)==getf(p[j][np[j]].second))
							np[j]++;
			}
//			cerr<<i<<" "<<now<<endl;
			ans=min(ans,now);
		}
		printf("%lld",ans);
		return 0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	estidi::main();
	return 0;
}
