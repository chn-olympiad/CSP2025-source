#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define F(i,r,l) for(int i=r;i>=l;--i)
#define int long long
#define ULL unsigned long long
#define read(n) {int _x=0,_t=1;char _c=getchar();while(!isdigit(_c)){if(_c=='-')_t=-1;_c=getchar();}while(isdigit(_c))_x=_x*10+_c-'0',_c=getchar();n=_x*_t;}
using namespace std;
const int N=100008;
int T,n,ans;
struct node{
	int d[4],id,op,dx;
	void clear(){d[0]=d[1]=d[2]=d[3]=id=op=dx=0;}
}a[N];
int b[4][N],cnt[4];
bool cmp(int i,int j){
	return a[i].dx>a[j].dx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		f(i,1,n) a[i].clear();
		f(j,1,3) f(i,1,n+2) b[j][i]=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		f(i,1,n){
			read(a[i].d[1]);
			read(a[i].d[2]);
			read(a[i].d[3]);
			a[i].id=i;
			if(a[i].d[1]>=max(a[i].d[2],a[i].d[3])){
				a[i].op=1;
				a[i].dx=a[i].d[1]-max(a[i].d[2],a[i].d[3]);
				b[1][++cnt[1]]=i;
			}
			else if(a[i].d[2]>=max(a[i].d[1],a[i].d[3])){
				a[i].op=2;
				a[i].dx=a[i].d[2]-max(a[i].d[1],a[i].d[3]);
				b[2][++cnt[2]]=i;
			}
			else{
				a[i].op=3;
				a[i].dx=a[i].d[3]-max(a[i].d[2],a[i].d[1]);
				b[3][++cnt[3]]=i;
			}
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			f(i,1,n) ans+=a[i].d[a[i].op];
			printf("%lld\n",ans);
			continue;
		}
		f(j,1,3) sort(b[j]+1,b[j]+cnt[j]+1,cmp);
		f(j,1,3){
			if(cnt[j]>n/2){
				F(i,cnt[j],n/2+1){
					int Id=b[j][i]; 
					if(j==1) ans+=max(a[Id].d[2],a[Id].d[3]);
					else if(j==2) ans+=max(a[Id].d[1],a[Id].d[3]);
					else ans+=max(a[Id].d[1],a[Id].d[2]);
				}
				f(i,1,n/2){
					int Id=b[j][i];
					ans+=a[Id].d[a[Id].op]; 
				}
			}
			else{
				f(i,1,cnt[j]){
					int Id=b[j][i];
					ans+=a[Id].d[a[Id].op];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
#include<bits.stdc++/h>
using namesapce std;
int mian(){
	//freopen("club.out","R",stdin);
	//froepen("1.out","w",stdout)
	return 1;
}
I love CCF.
I love xzy(or someone who finds me).
Why does xzy(or you) count it almost every year? 
To have fun?Or to find someone careless?
Or just to take a break?
Maybe you have guessed who I am.
But I have been AFO really.
*/
