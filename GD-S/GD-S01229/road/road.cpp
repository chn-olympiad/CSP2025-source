#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s[10005],ans,cnt,a,b,c,bj[2000005],val[10005],t[1005],sum,l,r,ans2,mm,p[1005][1005];
bool flag;
vector<long long>fb[1005];
struct stu {
	long long st,en,w;
}f[2000005];
stu fa[1005];
inline bool cmp(stu f1,stu f2) {
	return f1.w<f2.w;
}
inline long long find(long long x){
	return s[x]==x?x:(s[x]=find(s[x]));
}
inline void Kru() {
	for(long long i=1;i<=m+mm;i++) {
		long long x=find(f[i].st),y=find(f[i].en);
		if(x==y) continue;
		ans+=f[i].w;
		s[x]=y;
		cnt++;
		if(cnt==n-1) return ;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) s[i]=i;
	for(long long i=1;i<=m;i++) scanf("%lld%lld%lld",&f[i].st,&f[i].en,&f[i].w);
		sort(f+1,f+m+1,cmp);
	if(k==0) {
		Kru();
		cout<<ans;
		return 0;
	}
	if(n<=1000&&m<=100000) {
		Kru();
		ans2=ans;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				p[i][j]=1e15; 
		for(long long i=1;i<=n;i++) {
			long long x=f[i].st,y=f[i].en,z=f[i].w;
			p[x][y]=min(p[x][y],z);
			p[y][x]=min(p[y][x],z);
		}
		for(long long l=1;l<=k;l++) {
			mm=0;
			cin>>val[l];
			flag=false;
			for(long long j=1;j<=n;j++) 
				scanf("%lld",&t[j]);
			for(long long i=1;i<=n;i++) {
				for(long long j=1;j<=n;j++) {
					if(i==j) continue;
						if(p[i][j]>=t[j]+t[i]) {
							mm++;
							f[m+mm].st=i,f[m+mm].en=j,f[m+mm].w=t[i]+t[j];
						};
					
				}
			}
			ans=0;
			for(long long i=1;i<=n;i++) s[i]=i;
			
			sort(f+1,f+m+mm+1,cmp);
			//for(long long i=1;i<=n+mm;i++) cout<<f[i].st<<" "<<f[i].en<<" "<<f[i].w<<endl;
			Kru();
			if(ans2>=val[l]+ans) {
				flag=false;
				ans2=val[l]+ans;
				for(long long i=1;i<=n;i++) {
					for(long long j=1;j<=n;j++) {
						if(i==j) continue;
							if(p[i][j]>=t[j]+t[i]) {
								p[i][j]=t[i]+t[j];
								p[j][i]=p[i][j];
								if(!flag) p[i][j]+=val[l],flag=true;
								
							};
					
					}
				}
				m=0;
				for(long long i=1;i<=n;i++)
					for(long long j=i+1;j<=n;j++)
						if(p[i][j]!=1e15) {
							f[++m].st=i;
							f[m].en=j;
							f[m].w=p[i][j];
						}
			}
			
		}
		cout<<ans2;
	}
	else {
		ans=0;
		Kru();
		cout<<ans;
	}
		
	return 0;
}
