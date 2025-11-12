#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define mk make_pair
#define N 100009
using namespace std;
inline char nc(){static char buf[1<<20],*p=buf,*q=buf;return p==q&&(q=(p=buf)+fread(buf,1,1<<20,stdin),p==q)?EOF:*p++;}
inline ll rd(){bool f=0;char ch=nc();while(ch<'0'||ch>'9')f|=(ch=='-'),ch=nc();ll ans=0;while(ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=nc();return f?-ans:ans;}
char buf[1<<20],*p3=buf;inline void pc(char c){p3-buf<=1<<20?*p3++=c:(fwrite(buf,1,p3-buf,stdout),p3=buf,*p3++=c);}
inline void wt(ll x){if(x<0)x=-x,pc('-');if(x>9)wt(x/10);pc(x%10+'0');}
int t,n,a[N][3];
vector<int>V[3],E;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("Mikoto.txt","w",stdout);
	t=rd();
	while(t--){
		n=rd();V[0].clear(),V[1].clear(),V[2].clear(),E.clear();
		int ans=0;
		for(int i=1;i<=n;i++){
			a[i][0]=rd(),a[i][1]=rd(),a[i][2]=rd();
			int mx=max({a[i][0],a[i][1],a[i][2]});
			if(mx==a[i][0])V[0].eb(i);else if(mx==a[i][1])V[1].eb(i);else V[2].eb(i);
			ans+=mx;
		}
		if(V[0].size()>n/2){
			for(auto x:V[0])E.eb(a[x][0]-max(a[x][1],a[x][2]));
			sort(E.begin(),E.end());
			int dt=V[0].size()-n/2;
			for(int i=0;i<dt;i++)ans-=E[i];
		}
		else if(V[1].size()>n/2){
			for(auto x:V[1])E.eb(a[x][1]-max(a[x][0],a[x][2]));
			sort(E.begin(),E.end());
			int dt=V[1].size()-n/2;
			for(int i=0;i<dt;i++)ans-=E[i];
		}
		else if(V[2].size()>n/2){
			for(auto x:V[2])E.eb(a[x][2]-max(a[x][0],a[x][1]));
			sort(E.begin(),E.end());
			int dt=V[2].size()-n/2;
			for(int i=0;i<dt;i++)ans-=E[i];
		}
		wt(ans),pc('\n');
	}
	fwrite(buf,1,p3-buf,stdout);
	return 0;
}
