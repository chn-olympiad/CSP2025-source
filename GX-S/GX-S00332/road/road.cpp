#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,c[15],lp[15][10005],top,f[1000005],mm,t1,t2;
long long ans,anss;
struct line{
	int u,v,w;
}b[1000005],st[1000005];
bool cmp(line x,line y){
	return x.w<y.w;
}
int fd(int x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
void hb(int x,int y){
	f[fd(x)]=fd(y);
	return;
}
void kk(){
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(fd(b[i].u)==fd(b[i].v))continue;
		hb(fd(b[i].u),fd(b[i].v));
		ans+=b[i].w;
		cnt--;
		if(!cnt)break;
	}
	return;
}
void kk2(){
	sort(st+1,st+top+1,cmp);
	t1=1,t2=1;
	for(int i=1;i<=mm;i++){
		int u,v,w;
		if(b[t1].w<st[t2].w){
			u=b[t1].u;
			v=b[t1].v;
			w=b[t1].w;
			t1++;
		}else{
			u=st[t2].u;
			v=st[t2].v;
			w=st[t2].w;
			t2++;
		}
		if(fd(u)==fd(v))continue;
		hb(fd(u),fd(v));
		anss+=w;
		cnt--;
		if(!cnt)break;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>b[i].u>>b[i].v>>b[i].w;
	cnt=n-1;
	kk();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>lp[i][j];
	}
	for(int i=1;i<(1<<k);i++){
		top=0;
		cnt=n-1;
		mm=m;
		anss=0;
		for(int j=0;j<k;j++){
			if((1<<j)&i){
				cnt++;
				for(int o=1;o<=n;o++)mm++,st[++top].u=j+1+n,st[top].v=o,st[top].w=lp[j+1][o];
				anss+=c[j+1];
			}
		}
		for(int j=1;j<=n+k;j++)f[j]=j;
		kk2();
		ans=min(ans,anss);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
