#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6,mod=1e9+9;
const ll base=233333;
int n,q;
int L1;
ll pw[N+5];
ll hh[2] [N+5];
int len[N+5];
char ch[2] [N+5];
vector<char> s[N+5] [2];
vector<ll> h[N+5] [2];
void prepare(){
	pw[0]=1;
	for(int i=1;i<=N;++i)
		pw[i]=pw[i-1]*base%mod;
}
ll geth(int id1,int id2,int x,int y){
	if(x>y)
		return 0;
	if(x==0)
		return h[id1] [id2] [y];
	return (h[id1] [id2] [y]-h[id1] [id2] [x-1]*pw[y-x+1]%mod+mod)%mod;
}
ll gethh(int id,int x,int y){
	if(x>y)
		return 0;
	return (hh[id] [y]-hh[id] [x-1]*pw[y-x+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	prepare();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%s%s",ch[0]+1,ch[1]+1);
		len[i]=strlen(ch[0]+1);
		L1+=len[i];
		for(int j=0;j<=1;++j)
			for(int k=1;k<=len[i];++k)
				s[i] [j].emplace_back(ch[j] [k]);
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=1;++j)
			for(int k=0;k<len[i];++k){
				if(k)
					h[i] [j].emplace_back((h[i] [j] [k-1]*base+s[i] [j] [k]-'a')%mod);
				else h[i] [j].emplace_back(s[i] [j] [k]-'a');
			}
	while(q--){
		scanf("%s%s",ch[0]+1,ch[1]+1);
		int l=strlen(ch[0]+1);
		for(int i=0;i<=1;++i)
			for(int j=1;j<=l;++j)
				hh[i] [j]=(hh[i] [j-1]*base+ch[i] [j]-'a')%mod;
		int st=0,ed=0;
		for(int i=1;i<=l;++i)
			if(ch[0] [i]!=ch[1] [i]){
				if(!st)
					st=i;
				ed=i;
			}
		if(!ed){
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=0;j<=len[i]-1-(ed-st+1)+1;++j){
				int k=j+(ed-st+1)-1;
				if(j+1>st||len[i]-k>(l-ed+1))
					continue;
				if(geth(i,0,j,k)==gethh(0,st,ed)&&geth(i,1,j,k)==gethh(1,st,ed))
					if(geth(i,0,0,j-1)==geth(i,1,0,j-1)&&geth(i,0,0,j-1)==gethh(0,st-j,st-1)&&geth(i,0,k+1,len[i]-1)==geth(i,1,k+1,len[i]-1)&&geth(i,0,k+1,len[i]-1)==gethh(0,ed+1,ed+(len[i]-k)-1))
						++ans;
			}
		printf("%d\n",ans);
	}
	return 0;
}

