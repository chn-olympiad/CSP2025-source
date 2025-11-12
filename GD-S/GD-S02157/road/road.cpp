#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
struct line{
	int x,y,z;
}a[1000005],b[1000005],c[15][10005];
int fa[20005],tx,ty;
int minn[15],st[15];
ll v[15];
ll n,m,k,z,x,s,y,sum,ans;
struct node{
	int l;
	ll vl;
}o;
struct cmp1{
	bool operator ()(node aa,node bb){
		return aa.vl>bb.vl;
	}
};
priority_queue<node,vector<node>,cmp1> hp;
void read(ll &x){
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return ;
}
int find(int xx){
	if(fa[xx]!=xx) fa[xx]=find(fa[xx]);
	return fa[xx];
}
bool cmp(line aa,line bb){
	return aa.z<bb.z;
}
int main(){
	//road
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		read(x),read(y),read(z);
		a[i].x=x,a[i].y=y,a[i].z=z;
	}
	int top=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		tx=find(a[i].x),ty=find(a[i].y);
		if(tx!=ty){
			s+=a[i].z;
			fa[tx]=ty;
			b[++top]=a[i];
		}
	}
	m=top;
	for(int i=1;i<=k;i++){
		read(v[i]);
		for(int j=1;j<=n;j++){
			read(x);
			c[i][j].z=x,c[i][j].x=j,c[i][j].y=i+n;
		}
		sort(c[i]+1,c[i]+n+1,cmp);
	}
	ans=s;
	for(int i=0;i<(1<<k);i++){
		sum=0;
		st[0]=1;
		while(hp.size()>0) hp.pop();
		o.vl=b[1].z,o.l=0;
		hp.push(o);
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				sum+=v[j+1],st[j+1]=1;
				o.vl=c[j+1][1].z,o.l=j+1;
				hp.push(o);
			}
		}
		while(hp.size()>0){
			o=hp.top();
			hp.pop();
			z=o.vl;
			if(o.l==0){
				x=b[st[0]].x,y=b[st[0]].y,z=b[st[0]].z;
				tx=find(x),ty=find(y);
				st[0]++;
				if(st[0]<=m)
					o.l=0,o.vl=b[st[0]].z,hp.push(o);
			}
			else{
				x=c[o.l][st[o.l]].x,y=c[o.l][st[o.l]].y;
				z=c[o.l][st[o.l]].z;
				tx=find(x),ty=find(y);
				st[o.l]++;
				if(st[o.l]<=n)
					o.vl=c[o.l][st[o.l]].z,hp.push(o);
			}
			while(hp.size()>0&&tx==ty){
				o=hp.top();
				hp.pop();
				z=o.vl;
				if(o.l==0){
					x=b[st[0]].x,y=b[st[0]].y;
					tx=find(x),ty=find(y);
					st[0]++;
					if(st[0]<=m)
						o.l=0,o.vl=b[st[0]].z,hp.push(o);
				}
				else{
					x=c[o.l][st[o.l]].x,y=c[o.l][st[o.l]].y;
					tx=find(x),ty=find(y);
					st[o.l]++;
					if(st[o.l]<=n)
						o.vl=c[o.l][st[o.l]].z,hp.push(o);
				}
			}
			if(tx!=ty){
				fa[tx]=ty,sum+=z;
				if(sum>=ans) break;
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
