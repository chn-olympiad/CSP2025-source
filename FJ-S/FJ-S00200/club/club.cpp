#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
#define N 100005
int T,n,a[N][5],w[N];
struct add{int b,s;}l[N];
bool cmp1(int a,int b){return a>b;}
bool cmp2(add a,add b){return a.b>b.b;}
void stswap(int x,int y){
	swap(a[x][1],a[y][1]);
	swap(a[x][2],a[y][2]);
	swap(a[x][3],a[y][3]);
	swap(w[x],w[y]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(l,0,sizeof(l));
		memset(w,0,sizeof(w));
		int ans=0,e[5]={};
		cin>>n;
		for(int i=1;i<=n;++i)w[i]=i;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			l[i].s=a[i][1]+a[i][2]+a[i][3],l[i].b=i;
		}
		if(n==2){
			sort(a[1]+1,a[1]+4);
			sort(a[2]+1,a[2]+4);
			cout<<max(a[1][3]+a[2][2],a[2][3]+a[1][2])<<'\n';
			continue;
		}
		sort(l+1,l+n+1,cmp2);
		for(int i=1;i<=n;++i)if(l[i].b!=w[i])stswap(l[i].b,i);
		for(int i=1;i<=n;++i){
			int x=a[i][1],y=a[i][2],z=a[i][3],q[5];
			q[1]=x,q[2]=y,q[3]=z;
			sort(q+1,q+4,cmp1);
			if(q[1]==x){
				if(e[1]==n/2){
					if(q[2]==y)++e[2],ans+=y;
					else ++e[3],ans+=z;
				}else ++e[1],ans+=x;
			}else if(q[1]==y){
				if(e[2]==n/2){
					if(q[2]==x)++e[1],ans+=x;
					else ++e[3],ans+=z;
				}else ++e[2],ans+=y;
			}else{
				if(e[3]==n/2){
					if(q[2]==x)++e[1],ans+=x;
					else ++e[2],ans+=y;
				}else ++e[3],ans+=z;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
