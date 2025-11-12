#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5,V=2e5,mod=100024511,md=1053210149,b=37,k=31;
int n,q,m,ans,len[N],l,r,mid;
long long val1[N],val2[N],f[N],a[N],d[N];
long long val3[N],val4[N],g[N],h[N],p[N];
string s,x,y;
long long get1(int l,int r){
	if(l>r) return mod;
	return (a[r]-((a[l-1]*f[r-l+1])%mod)+mod)%mod;
}
long long get2(int l,int r){
	if(l>r) return mod;
	return (d[r]-((d[l-1]*f[r-l+1])%mod)+mod)%mod;
}
long long get3(int l,int r){
	if(l>r) return md;
	return (h[r]-((h[l-1]*g[r-l+1])%md)+md)%md;
}
long long get4(int l,int r){
	if(l>r) return md;
	return (p[r]-((p[l-1]*g[r-l+1])%md)+md)%md;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0]=1,g[0]=1;
	for(int i=1;i<=V;++i) f[i]=(f[i-1]*b)%mod,g[i]=(g[i-1]*k)%md;	
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s;
		len[i]=s.size();
		for(int j=0;j<len[i];++j) val1[i]=(val1[i]*b+s[j]-'a'+1)%mod,val3[i]=(val3[i]*k+s[j]-'a'+1)%md;
		cin>>s;
		for(int j=0;j<len[i];++j) val2[i]=(val2[i]*b+s[j]-'a'+1)%mod,val4[i]=(val4[i]*k+s[j]-'a'+1)%md;
	}
	while(q--){
		cin>>x>>y,ans=0;
		m=x.size();
		x=' '+x,y=' '+y;
		for(int i=1;i<=m;++i) a[i]=(a[i-1]*b+x[i]-'a'+1)%mod,h[i]=(h[i-1]*k+x[i]-'a'+1)%md;
		for(int i=1;i<=m;++i) d[i]=(d[i-1]*b+y[i]-'a'+1)%mod,p[i]=(p[i-1]*k+y[i]-'a'+1)%md;
		for(int i=1,s,t,tmp;i<=n;++i){
			tmp=m-len[i]+1;
			s=1,t=tmp;
			l=0,r=tmp+1;
			while(l+1!=r){
				mid=l+r>>1;
				if(get1(1,mid-1)!=get2(1,mid-1)||get3(1,mid-1)!=get4(1,mid-1)) r=mid;
				else l=mid;
			}
			t=r;
			l=0,r=tmp+1;
			while(l+1!=r){
				mid=l+r>>1;
				if(get1(mid+len[i],m)!=get2(mid+len[i],m)||get3(mid+len[i],m)!=get4(mid+len[i],m)) l=mid;
				else r=mid;
			}
			s=l;
			for(int j=s+1;j<t;++j){
				if(get1(j,j+len[i]-1)==val1[i]&&get2(j,j+len[i]-1)==val2[i]){
					if(get3(j,j+len[i]-1)==val3[i]&&get4(j,j+len[i]-1)==val4[i]){
						++ans;
						break;						
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
5 3
abc xyz
xyz abc
fabc fxyz
fxyz fabc
ab xy
fabc fxyz
poilkjfabcpoilkj poilkjfxyzpoilkj
iopjklbnmab iopjklbnmxy

1 1
ab cd
afabkopabj afabkopcdj
*/
