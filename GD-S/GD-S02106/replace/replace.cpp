#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2.5e6+5,p=37,mod=1e9+7;
int n,m,idx=0,idxx=0,ha1[M],ha2[M],pw[M];
char s1[M],s2[M];
map<int,int>pre[N],nxt[N];
map<pair<int,int>,int>id,num;
vector<int>llen[N],prelen[N];
int H1(int l,int r){
	return (ha1[r]-1ll*ha1[l-1]*pw[r-l+1]%mod+mod)%mod;
}
int H2(int l,int r){
	return (ha2[r]-1ll*ha2[l-1]*pw[r-l+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n>>m;
	pw[0]=1;
	for(int i=1;i<=2500000;i++)pw[i]=1ll*pw[i-1]*p%mod;
	while(n--){
		cin >>s1+1>>s2+1;
		int len=strlen(s1+1),l=len,r=1,flag=0;
		for(int j=1;j<=len;j++)if(s1[j]!=s2[j])flag=1,l=min(l,j),r=max(r,j);
		if(!flag)continue;
		int k1=0,k2=0,hs=0,ht=0;
		for(int j=1;j<=len;j++){
			k1=(1ll*k1*p%mod+s1[j]-'a'+1)%mod;
			k2=(1ll*k2*p%mod+s2[j]-'a'+1)%mod;
		}
		num[make_pair(k1,k2)]++;
		for(int j=l;j<=r;j++){
			hs=(1ll*hs*p%mod+s1[j]-'a'+1)%mod,ht=(1ll*ht*p%mod+s2[j]-'a'+1)%mod;
		}
		if(!id[make_pair(hs,ht)])id[make_pair(hs,ht)]=++idx;
		int pos=id[make_pair(hs,ht)];
		if(!pre[pos][l-1])pre[pos][l-1]=++idxx,prelen[pos].push_back(l-1);
		if(!nxt[pre[pos][l-1]][len-r]){
			llen[pre[pos][l-1]].push_back(len-r);
			nxt[pre[pos][l-1]][len-r]=1;
		}
	}
	while(m--){
		cin >>s1+1>>s2+1;
		int len=strlen(s1+1),l=len,r=1;
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j])l=min(l,j),r=max(r,j);
			ha1[j]=(1ll*p*ha1[j-1]%mod+s1[j]-'a'+1)%mod;
			ha2[j]=(1ll*p*ha2[j-1]%mod+s2[j]-'a'+1)%mod;
		}
		int hs=0,ht=0;
		for(int j=l;j<=r;j++){
			hs=(1ll*hs*p%mod+s1[j]-'a'+1)%mod,ht=(1ll*ht*p%mod+s2[j]-'a'+1)%mod;
		}
		int pos=id[make_pair(hs,ht)];
		if(!pos){
			cout <<"0\n";
			continue;
		}
		int ans=0;
		for(int j=0;j<prelen[pos].size();j++){
			int x=prelen[pos][j],pos_=pre[pos][x];
			if(x>l-1)continue;
			for(int k=0;k<llen[pos_].size();k++){
				int y=llen[pos_][k];
				if(y>len-r)continue;
				ans+=num[make_pair(H1(l-x,r+y),H2(l-x,r+y))];
			}
		}
		cout <<ans<<"\n";
	}
	return 0;
}

