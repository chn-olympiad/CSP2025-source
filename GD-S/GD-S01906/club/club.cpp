#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
bool vis[N];
ll T,n,ans,s[N],a[N][5];
vector<ll>v[5];
inline ll read(){
	ll x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x;
}
ll work(ll x){
	ll p[5]={a[x][1],a[x][2],a[x][3]};
	sort(p,p+3);
	return p[2]-p[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read(),ans=0;
		for(ll i=1;i<=n;vis[i++]=0){
			ll mx=0,id=0;
			for(ll j=1;j<=3;j++){
				a[i][j]=read();
				if(mx<a[i][j]) mx=a[i][j],id=j;
			}
			ans+=mx;
			v[id].push_back(i);
		}
		for(ll i=1,len;i<=3;i++)
			if((len=v[i].size())>n/2){
				for(ll j=0;j<len;j++)
					s[j]=work(v[i][j]);
				sort(s,s+len);
				for(ll j=0;j<len-n/2;j++) ans-=s[j];
				break;
			}
		printf("%lld\n",ans);
		v[1].clear(),v[2].clear(),v[3].clear();
	}
	return 0;
}
//COYG!!!
//服了，i j打反了调了我100min啊，我真的是个人物    希望快读不要错，今天才背的 
