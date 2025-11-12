#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char ch='?';
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+(ch-'0'),ch=getchar();
	return x;
}
int n,m,k,u,v,w,f[10025];
int dis[15][10005],c[15],num;
int fa(int x){
	if(f[x]==x)return x;
	f[x]=fa(f[x]);
	return f[x];
}
long long ans=0x3f3f3f3f3f3f3f3f,cur;
bool a[15];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >Q,qq,q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		qq.push({w,{u,v}});
	}
	for(int i=1;i<=n;i++)f[i]=i;
	while(!qq.empty()){
		pair<int,pair<int,int> >p=qq.top();qq.pop();
		u=p.second.first,v=p.second.second;
		if(fa(u)!=fa(v)){
			Q.push(p);
			f[fa(u)]=fa(v);
		}
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)dis[i][j]=read();
	}
	for(int i=0;i<(1<<k);i++){
		cur=0,num=n-1;
		q=Q;
		for(int j=0;j<k;j++)
			if(i&(1<<j)){
				num++;
				cur+=c[j+1];
				for(int l=1;l<=n;l++)q.push({dis[j+1][l],{j+n+1,l}});
			}
		for(int j=1;j<=n+k;j++)f[j]=j;
		while(!q.empty()){
			pair<int,pair<int,int> >p=q.top();q.pop();
			u=p.second.first,v=p.second.second;
			if(fa(u)!=fa(v)){
				f[fa(u)]=fa(v);
				num--;
				cur+=p.first;
				if(num==0)break;
			}
		}
		ans=min(ans,cur);
//		cout<<i<<" "<<cur<<endl;
	}
	cout<<ans;
	return 0;
}
//80pts
