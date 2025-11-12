#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,has[5000005],hass[5000005],p2[5000005],vis[200005];
string s1,s2,x,y;
const int mod=1e9+7,p=998244353;
struct o{
	int x,y,len,cs,mw;
}a[200005];
int get(int l,int r){
	return ((has[r]-(l==0?0:has[l-1])*p2[r-l+1]%mod)%mod+mod)%mod;
}
int get2(int l,int r){
	return ((hass[r]-(l==0?0:hass[l-1])*p2[r-l+1]%mod)%mod+mod)%mod;
} 
signed main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p2[0]=1;
	for(int i=1;i<=5000000;i++)p2[i]=p2[i-1]*p%mod;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		a[i].len=s1.size();
		for(int j=0;j<s1.size();j++){
			a[i].x=(a[i].x*p%mod+s1[j])%mod;
			a[i].y=(a[i].y*p%mod+s2[j])%mod;
		}
		int cs=-1,mw=-1;
		for(int j=0;j<s1.size();j++){
			if(cs==-1&&s1[j]!=s2[j])cs=j;
			if(s1[j]!=s2[j])mw=j;
		}
		a[i].cs=cs,a[i].mw=mw;
	}
	while(q--){
		cin>>x>>y;
		int cs=-1,mw=-1,ans=0;
		for(int i=0;i<x.size();i++){
			if(cs==-1&&x[i]!=y[i])cs=i;
			if(x[i]!=y[i])mw=i;
			has[i]=hass[i]=0;
		}
		for(int i=0;i<x.size();i++){
			has[i]=((i==0?0:has[i-1])*p+x[i])%mod;
			hass[i]=((i==0?0:hass[i-1])*p+y[i])%mod;
		}
		if(cs==-1){
			for(int i=1;i<=n;i++)vis[i]=0;
			for(int i=0;i<x.size();i++){
				for(int j=1;j<=n;j++){
					if(vis[j])continue;
					if(i+a[j].len-1>=x.size())continue;
					if(get(i,i+a[j].len-1)==a[j].x&&get2(i,i+a[j].len-1)==a[j].y){
						ans++;
						vis[j]=1;
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(mw-cs!=a[i].mw-a[i].cs||a[i].cs==-1)continue;
				if(a[i].cs>cs)continue;
				if(x.size()-mw<a[i].len-a[i].mw)continue;
				if(get(cs-a[i].cs,cs-a[i].cs+a[i].len-1)==a[i].x&&get2(cs-a[i].cs,cs-a[i].cs+a[i].len-1)==a[i].y)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
