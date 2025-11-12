#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define MP make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define ep emplace
#define eb emplace_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++) 
#define per(i,j,k) for(int i=(j);i>=(k);i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
bool Mbe;

template<typename T>void chkmin(T&x,T y){if(y<x)x=y;}
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')f^=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')s=s*10+c-'0',c=getchar();
	return f?s:-s;
}

const int N=100005;
int n,a[N][3],id[N];
int cnt[3];

bool Med;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fprintf(stderr,"%.3lfMb\n",(&Mbe-&Med)/1024./1024.);
	for(int T=read();T--;){
		n=read();
		rep(i,1,n)rep(j,0,2)a[i][j]=read();
		int sum=0;
		memset(cnt,0,sizeof cnt);
		rep(i,1,n){
			int p=0;
			rep(j,1,2)if(a[i][j]>a[i][p])p=j;
			cnt[p]++,id[i]=p,sum+=a[i][p];
		}
		rep(j,1,2){
			if(cnt[j]>n/2){
				rep(i,1,n){
					swap(a[i][0],a[i][j]);
					if(!id[i]||id[i]==j)id[i]^=j;
				}
				swap(cnt[0],cnt[j]);
			}
		}
		if(cnt[0]>n/2){
			vector<int>vec;
			rep(i,1,n)if(!id[i]){
				vec.eb(a[i][0]-max(a[i][1],a[i][2]));
			}
			sort(ALL(vec));
			rep(i,0,cnt[0]-n/2-1)sum-=vec[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
