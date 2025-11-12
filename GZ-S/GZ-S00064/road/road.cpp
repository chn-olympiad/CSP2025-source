#include<bits/stdc++.h>//GZ-S00064 安顺市第二高级中学 刘科 
using namespace std;
const int kMaxN=1e6+7;
int n,m,k,a[kMaxN],b[20][kMaxN],c[kMaxN],ans,ac;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return f*x;
}
struct V{
	int l,r,m;
}v[kMaxN];
bool cmp(const V& a,const V& b){
	return a.m>b.m;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
    n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		v[i].l=read(),v[i].r=read(),v[i].m=read();
		a[v[i].l]++,a[v[i].r]++;
		ans+=v[i].m;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			b[i][j]=read();
		}
	}
	sort(v+1,v+n+1,cmp);
	for(int i=1;i<=m;i++){
		int x=v[i].l,y=v[i].r,z=v[i].m;
		if(a[x]>1&&a[y]>1){
			a[x]--,a[y]--;
			ans-=z;
		}
	}
	ac=ans;
	cout<<ac<<'\n';
	return 0;
} 
