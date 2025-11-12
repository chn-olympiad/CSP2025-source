#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=b;i>=(int)a;i--)
const int N=1e5+10;
const ll inf=1e9+10;
const ll mod=1e9+7;
using Vl=vector<ll>;
using PI=array<ll,3>;
int T,n,_1[N],_2[N],_3[N],ct1,ct2,ct3,d[N];
ll f[2][210][210];
PI a[N];
bool cmp(int x,int y){return d[x]<d[y];}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		FOR(i,1,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(n<=200){
			FOR(x,0,n/2) FOR(y,0,n/2) f[0][x][y]=f[1][x][y]=0;
			FOR(i,1,n){
				int ni=i&1,ci=ni^1;
				FOR(x,0,n/2){
					FOR(y,0,n/2){
						if(i-x-y>n/2||i-x-y<0) continue; 
						if(i-1-x-y>=0)f[ni][x][y]=f[ci][x][y]+a[i][2];
						if(x>=1) f[ni][x][y]=max(f[ni][x][y],f[ci][x-1][y]+a[i][0]);
						if(y>=1) f[ni][x][y]=max(f[ni][x][y],f[ci][x][y-1]+a[i][1]);
					}
				}
			}
			ll ans=0;
			FOR(x,0,n/2) FOR(y,0,n/2) if(n-x-y<=n/2) ans=max(ans,f[n&1][x][y]);
			cout<<ans<<'\n';
		}else{
			ll ans=0;ct1=ct2=ct3=0;
			FOR(i,1,n){
				ll x,y,z;x=a[i][0],y=a[i][1],z=a[i][2];
				if(x>=y&&x>=z) ans+=x,_1[++ct1]=i,d[i]=min(x-y,x-z);
				else if(y>=x&&y>=z) ans+=y,_2[++ct2]=i,d[i]=min(y-x,y-z);
				else ans+=z,_3[++ct3]=i,d[i]=min(z-x,z-y);
			}
			if(ct1<=n/2&&ct2<=n/2&&ct3<=n/2) cout<<ans<<'\n';
			else if(ct1>n/2){
				sort(_1+1,_1+ct1+1,cmp);
				FOR(i,1,ct1-n/2) ans-=d[_1[i]];
				cout<<ans<<'\n';
			}else if(ct2>n/2){
				sort(_2+1,_2+ct2+1,cmp);
				FOR(i,1,ct2-n/2) ans-=d[_2[i]];
				cout<<ans<<'\n';
			}else{
				sort(_3+1,_3+ct3+1,cmp);
				FOR(i,1,ct3-n/2) ans-=d[_3[i]];
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}

