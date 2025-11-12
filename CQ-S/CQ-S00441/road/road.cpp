#include<bits/stdc++.h> 
using namespace std;
namespace MYQ{
	int n,m,k,f[11001],si[11001],c[15],en;
	long long ans;
	struct ac{
		int x,y,z;
	}a[1000011],b[15][11011];
	vector<ac>xy[1100];
	bool cmp(ac x,ac y){
		return x.z<y.z;
	}
	int zbb(int x){
		if(f[x]==x)
			return x;
		return f[x]=zbb(f[x]);
	}
	inline void hb(int x,int y){
		x=zbb(x),y=zbb(y);
		if(si[x]>si[y])
			swap(x,y);
		si[y]+=si[x];
		f[x]=y;
	}
	void js(int x,long long y){
		long long an=y;
		for(int i=1;i<=n+k;i++)
			f[i]=i,si[i]=1;
		for(int i=1;i<=en;i++)
			if(zbb(a[i].x)!=zbb(a[i].y)){
				hb(a[i].x,a[i].y);
				an+=a[i].z;
				xy[x].push_back(a[i]);
			}
		if(x==0)
			ans=an;
		else
			ans=min(ans,an);
	}
	inline int read() {
		int x=0;
		char c=getchar();
		while(c<'0'||'9'<c)
			c=getchar();
		while('0'<=c&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}
		return x;
	}
	int main(){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
			a[i].x=read(),a[i].y=read(),a[i].z=read();
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++){
				int x=read();
				b[i][j].x=i+n;
				b[i][j].y=j;
				b[i][j].z=x;
			}
			sort(b[i]+1,b[i]+n+1,cmp);
		}
		sort(a+1,a+m+1,cmp);
		en=m;
		js(0,0);
		for(int i=1;i<(1<<k);i++){
			en=0;
			long long xx=0;
			for(int j=0;j<k;j++)
				if(i&(1<<j))
					xx+=c[j+1];
			for(int j=0;j<k;j++)
				if(i&(1<<j)){
					for(int x=0,y=1;x<xy[i^(1<<j)].size()||y<=n;){
						if(x<xy[i^(1<<j)].size()&&(y>n||xy[i^(1<<j)][x].z<=b[j+1][y].z))
							a[++en]=xy[i^(1<<j)][x],x++;
						else
							a[++en]=b[j+1][y],y++;
					}
					break;
				}
			js(i,xx);
		}
		printf("%lld",ans);
		return 0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	MYQ::main();
	return 0;
}
