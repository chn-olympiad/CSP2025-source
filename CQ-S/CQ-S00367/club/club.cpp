#include <cstdio>
#include <algorithm>
int Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
void w(T x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
constexpr int N=100010;
int T,n,i,j,k,ans,p,q,v[3][N],m[3];
struct ss{int v[3];}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	r(T);
	while(T--){
		for(i=0;i<3;i++)m[i]=0;
		ans=0;
		r(n);
		for(i=1;i<=n;i++){
			p=q=-1;
			for(j=0;j<3;j++){
				r(a[i].v[j]);
				if(p==-1||a[i].v[j]>a[i].v[p]){
					q=p;
					p=j;
				}
				else if(q==-1||a[i].v[j]>a[i].v[q])q=j;
			}
			ans+=a[i].v[p];
			v[p][++m[p]]=a[i].v[q]-a[i].v[p];
		}
		for(i=0;i<3;i++){
			if(m[i]<=n>>1)continue;
			std::sort(v[i]+1,v[i]+m[i]+1);
			while(m[i]>n>>1)ans+=v[i][m[i]--];
		}
		w(ans);
		putchar(10);
	}
	return 0;
}