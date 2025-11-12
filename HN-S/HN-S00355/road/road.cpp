#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define int long long
int n,m,k,f[10010],ans,c[10010],n1,m1,cnt1;
struct node{
	int u,v,w;
}a[N];
inline int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline bool cmp(node a,node b){
	return a.w<b.w;
}
inline int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
inline int kls(int m0){
	int ans1=0,cnt=0,i=1;
	for(int i=1;i<=n1;i++) f[i]=i;
	sort(a+1,a+m0+1,cmp);
	while(1&&i<=m0){
		int fu=find(a[i].u);
		int fv=find(a[i].v);
		if(fu!=fv){
			f[fu]=fv;
			if(a[i].v==n1){
				cnt1++;
				a[++m].u=a[i].u;
				a[m].v=a[i].v;
				a[m].w=a[i].w;
			}
			ans1+=a[i].w;
			cnt++;
			if(cnt==n1-1) break;
		}
		i++;
	}
//	cout<<cnt<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<f[i]<<endl;
//	}
	return ans1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	n1=n+1;
	m1=m;
	ans=kls(m);
	while(k--){
		int co,ans1=0;
		co=read();
		for(int i=1;i<=n;i++){
			m1++;
			a[m1].u=i;
			a[m1].v=n1;
			a[m1].w=read();
		}
//		ans1=kls(m1);
//		if(ans1+co<ans) ans=ans1+co;
//		else m-=cnt1,n1--;
//		m1=m;
//		n1++;
	}
	cout<<ans;
	return 0;
}

