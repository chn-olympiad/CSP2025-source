#include<bits/stdc++.h>
#define int long long
using namespace std;
struct U{
	int x,y,co;
}w[2000006],ww[2000006];
int n,m,k,p,ans,cnt;
int c[100005],a[10004][10004],f[10004],ac[1000006],us[1000006];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
} 
bool cmp(U x,U y){
	return x.co<y.co;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		w[i].x=read();
		w[i].y=read();
		w[i].co=read();
	}
	p=m;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				w[++p].x=j;w[p].y=l;
				w[p].co=a[i][j]+a[i][l]+c[i];
			}
		}
	} 
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(w+1,w+p+1,cmp);
	for(int i=1;i<=p;i++){
		x=find(w[i].x);y=find(w[i].y);
		if(x!=y){
			f[y]=x;
			cnt++;
			ans+=w[i].co;
//			cout<<ww[p].x<<' '<<ww[p].y<<' '<<ww[p].co<<'\n';
			if(cnt>=n-1) break;
		}
	}
//	cout<<p<<'\n';
	cout<<ans<<'\n';
	return 0;
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
out:13
*/
}

