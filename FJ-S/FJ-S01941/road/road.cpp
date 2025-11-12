#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10005],ans=0,e=0,b[15][10005];
struct hhhh{
	int u,v,w;
}a[1000005];
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
bool cmp(hhhh xx,hhhh yy){
	return xx.w<yy.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void klu(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v)){
			e++;
			fa[find(a[i].u)]=find(a[i].v);
			ans+=a[i].w;
		}
		if(e==n-1){
			break;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		a[i].u=read();a[i].v=read();a[i].w=read();
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			b[i][j]=read();
		}
	}
	klu();
	cout<<ans<<endl;
	return 0;
}
