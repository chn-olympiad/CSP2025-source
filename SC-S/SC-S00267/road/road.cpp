#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+15,MAXN2=2e5+10,MAXM=1e6+15;
int n,m,k,cnt,t,top,top2,f[MAXN],siz[MAXN],c[15],book[15];
long long ans;
struct bian{
	int x,y,w;
}b[MAXM],d[15][MAXN],q[MAXN2],q2[MAXN2];
bool cmp(bian a,bian b){
	return a.w<b.w;
}
int find(int i){
	if(f[i]==i)return i;
	return f[i]=find(f[i]);
}
inline int read(){
	char ch=' ';
	int re=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')re=re*10+ch-'0',ch=getchar();
	return re;
}
void go(int u){
	if(u==k+1){
		long long s=0;
		for(int i=1;i<=t;i++)q[i]=q2[i]=b[i];
		top=top2=t;
		cnt=n;
		for(int i=1;i<=k;i++){
			if(!book[i])continue;
			cnt++;
			s+=c[i];
			if(s>=ans)return;
			int j=1,z=1;
			top=0;
			while(j<=top2||z<=n){
				if(j>top2)q[++top]=d[i][z],z++;
				else if(z>n)q[++top]=q2[j],j++;
				else if(d[i][z].w<q2[j].w)q[++top]=d[i][z],z++;
				else q[++top]=q2[j],j++;
			}
			for(j=1;j<=top;j++)q2[j]=q[j];
			top2=top;
		}
		for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;
		for(int i=1;i<=top;i++){
			int zx=find(q[i].x),zy=find(q[i].y);
			if(zx!=zy){
				s+=q[i].w;
				if(s>=ans)return;
				if(siz[zx]<siz[zy]){
					f[zx]=zy;
					siz[zy]+=siz[zx];
				}else{
					f[zy]=zx;
					siz[zx]+=siz[zy];
				}
				cnt--;
				if(cnt==1)break;
			}
		}
		ans=s;
		return;
	}
	book[u]=1;
	go(u+1);
	book[u]=0;
	go(u+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)b[i].x=read(),b[i].y=read(),b[i].w=read();
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	cnt=n;
	for(int i=1;i<=m;i++){
		int zx=find(b[i].x),zy=find(b[i].y);
		if(zx!=zy){
			b[++t]=b[i];
			ans+=b[i].w;
			if(siz[zx]<siz[zy]){
				f[zx]=zy;
				siz[zy]+=siz[zx];
			}else{
				f[zy]=zx;
				siz[zx]+=siz[zy];
			}
			cnt--;
			if(cnt==1)break;
		}
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			d[i][j].x=n+i,d[i][j].y=j;
			d[i][j].w=read();
		}
		sort(d[i]+1,d[i]+n+1,cmp);
	}
	go(1);
	cout<<ans;
	return 0;
}