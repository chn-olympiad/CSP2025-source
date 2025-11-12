#include<bits/stdc++.h>
#define sf scanf 
#define pf printf  
#define rep(x,y,z) for(int x=y;x<=z;x++) 
#define per(x,y,z) for(int x=y;x>=z;x--) 
using namespace std;
typedef long long ll;
namespace wing_heart {
	#define isdigit(x) (x>='0' && x<='9') 
	#define gc getchar_unlocked
	void read(int &x) {
		x=0;
		char ch=gc();
		while(!isdigit(ch)) ch=gc();
		while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch-'0'), ch=gc();
	}
	constexpr int N=1e5+7;
	int T;
	int n,a[N][3];
	int s,b[N];
	int cnt[3];
	struct piii {
		int id,x,op;
		bool operator < (piii b) const { return x < b.x; }
	};
	piii st[N<<1];
	int st0;
	bool vi[N];
	void main() {
		read(T);
		while(T--) {
			s=0;
			cnt[0]=cnt[1]=cnt[2]=0;
			read(n);
			rep(i,1,n) {
				int op=0;
				rep(j,0,2) read(a[i][j]);
				if(a[i][1]>a[i][op]) op=1;
				if(a[i][2]>a[i][op]) op=2;
				s+=a[i][op];
				b[i] = op;
				cnt[op]++;
			}
			if(cnt[0]>(n>>1) || cnt[1]>(n>>1) || cnt[2]>(n>>1)) {
				int x = 0;
				if(cnt[1]>cnt[x]) x=1;
				if(cnt[2]>cnt[x]) x=2;
				int x1=(x+1)%3, x2=(x1+1)%3;
				st0=0;
				rep(i,1,n) if(b[i]==x) st[++st0] = {i,a[i][x1]-a[i][x],x1}, st[++st0] = {i,a[i][x2]-a[i][x],x2};
				sort(st+1,st+st0+1);
				memset(vi,0,sizeof(vi));
				per(i,st0,1) {
					if(cnt[x]<=(n>>1)) break;
					if(!vi[st[i].id]) {
						vi[st[i].id]=1;
						s+=st[i].x;
						cnt[x]--;
						cnt[st[i].op]++;
					}
				}
				if(cnt[x1]>(n>>1) || cnt[x2]>(n>>1)) {
					x=x1,x1=x2;
					if(cnt[x1]>cnt[x]) swap(x,x1);
					st0=0;
					rep(i,1,n) if(b[i]==x) st[++st0] = {i,a[i][x1]-a[i][x],0};
					sort(st+1,st+st0+1);
					per(i,st0,1) {
						if(cnt[x]<=(n>>1)) break;
						s+=st[i].x;
						cnt[x]--;
						cnt[x1]++;
					}
				}
			}
			pf("%d\n",s);
		}
	}
} 
int main() {
	#ifdef LOCAL 
	// freopen("in.txt","r",stdin);
	freopen("my.out","w",stdout);
	#else 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif 
	wing_heart :: main();
}