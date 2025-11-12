#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=1000000000000000000ll;
bool v[100000];
int fa[100000];
struct sss{
	int x,y,w;
}s[2300005],f[2300005];
struct kkk{
	int id;
	int w[100005];
}c[20];
inline int find(int x){
	if(x!=fa[x]){
		return fa[x]=find(fa[x]);
	}
	return fa[x];
}
inline bool cmp(sss s1,sss s2){
	return s1.w<s2.w;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
//	cout<<ch<<"&&&"<<endl;
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	
	return x*f;
}
inline void work(){
	int cnt=m;
	long long sum=0;
	for(int i=1;i<=m;i++){
		s[i]=f[i];
	}
	int t=0;
	for(int i=1;i<=k;i++){
		if(v[i]==1){
			t++;
			sum+=c[i].id;
			if(sum>=ans)return;
//			sum+=c[i].w[i];
			for(int l=1;l<=n;l++){
//				if(l==i)continue;
				s[++cnt].x=n+t;
				s[cnt].y=l;
				s[cnt].w=c[i].w[l];
			}
		}
	}
	sort(s+1,s+cnt+1,cmp);
	int wasd=0;
	for(int i=1;i<=n+t;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int x=find(s[i].x);
		int y=find(s[i].y);
		if(x!=y){
			fa[x]=y;
			wasd++;
			sum+=s[i].w;
			if(sum>=ans)return;
			if(wasd==n+t-1)break;
		}
	}
//	if(sum==5182974424){
//		cout<<114514<<endl;
//	}
//	cout<<sum<<"***"<<ans<<endl;
	ans=min(ans,sum);
}
inline void dfs(int i){
	if(i==k+1){
		work();
		return;
	}
	v[i]=1;
	dfs(i+1);
	v[i]=0;
	dfs(i+1);
}
inline void work1(){
	int cnt=m;
//	cout<<114514<<endl;
//	int nt=0;
	for(int i=1;i<=k;i++){
		for(int l=1;l<=n;l++){
			if(c[i].w[l]==0){
				for(int k=1;k<=n;k++){
					if(k==l)continue;
					f[++cnt].x=l;
					f[cnt].y=k;
					f[cnt].w=c[i].w[k];
		//			nt++;
				}
			}
		}
	}
//	cout<<nt<<endl;
	long long sum=0;
	int wasd=0;
//	cout<<cnt<<endl;
	sort(f+1,f+cnt+1,cmp);
//	cout<<f[1].w<<" "<<f[2].w<<endl;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int x=find(f[i].x);
		int y=find(f[i].y);
		if(x!=y){
			fa[x]=y;
			wasd++;
			sum+=f[i].w;
			if(wasd==n-1)break;
		}
	}
	printf("%lld\n",sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();k=read();
	for(int i=1;i<=m;i++){
		f[i].x=read();
		f[i].y=read();
		f[i].w=read();
	}
	bool flag=false;
	for(int i=1;i<=k;i++){
		c[i].id=read();
		if(c[i].id!=0)flag=true;
		for(int l=1;l<=n;l++){
			c[i].w[l]=read();
		}
	}
	if(flag==false){
		work1();
		return 0;
	}
	dfs(1);
	printf("%lld\n",ans);
}
