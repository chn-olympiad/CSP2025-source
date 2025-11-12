#include<bits/stdc++.h>
#define ll int
#define PLL pair<ll,ll>
#define PPLL pair<PLL,PLL> 
using namespace std;
const int N=5000010;
const ll has1=131,has2=37,p1=1e9+7,p2=998244353;
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*y;
}
void write(long long x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
struct Tree{
	ll son[28];
	ll fail;
}t[N];
ll cnt,top;

ll n,Q;
long long ed[N],rt[N];
map<PPLL,ll> mp;
ll q[N],L,R;
long long ans;

void insert(ll rt,string s,string s1,ll id){
	ll u=rt;
	for(int i=0;i<s.size();i++){
		ll x=s[i]-'a';
		if(s[i]!=s1[i]) x=26;
		if(!t[u].son[x]) t[u].son[x]=++top;
		u=t[u].son[x];
	}
	ed[u]++;
}

void build(ll rt){
	L=1,R=0;q[++R]=rt;
	t[rt].fail=0;
	for(int i=0;i<=26;i++) t[0].son[i]=rt;
	while(L<=R){
		ll u=q[L++];
		ed[u]+=ed[t[u].fail];
		for(int i=0;i<=26;i++){
			if(!t[u].son[i]) t[u].son[i]=t[t[u].fail].son[i];
			else{
				t[t[u].son[i]].fail=t[t[u].fail].son[i];
				q[++R]=t[u].son[i];
			}
		}
	}
}

string s,s1;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	n=read(),Q=read();
	for(int i=1;i<=n;i++){
		s=s1="";
		char c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while('a'<=c&&c<='z') s+=c,c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while('a'<=c&&c<='z') s1+=c,c=getchar();
		
		ll X=0,Y=0,Z=0,W=0;
		if(s==s1) continue;
		ll L=0,R=s.size()-1;
		while(s[L]==s1[L]) L++;
		while(s[R]==s1[R]) R--;
		for(int j=L;j<=R;j++) X=((ll)X*has1+s[j])%p1,Y=((ll)Y*has2+s[j])%p2,Z=((ll)Z*has1+s1[j])%p1,W=((ll)W*has2+s1[j])%p2;
		ll tmp=0;
		if(!mp[{{X,Y},{Z,W}}]) tmp=mp[{{X,Y},{Z,W}}]=++cnt,rt[cnt]=++top;
		else tmp=mp[{{X,Y},{Z,W}}];
		insert(rt[tmp],s,s1,i);
	}
	for(int i=1;i<=cnt;i++) build(rt[i]);
	for(int i=1;i<=Q;i++){
		s=s1="";
		char c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while('a'<=c&&c<='z') s+=c,c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while('a'<=c&&c<='z') s1+=c,c=getchar();
		
		ll X=0,Y=0,Z=0,W=0;
		if(s.size()!=s1.size()){puts("0");continue;}
		ll L=0,R=s.size()-1;
		while(s[L]==s1[L]) L++;
		while(s[R]==s1[R]) R--;
		for(int j=L;j<=R;j++) X=((ll)X*has1+s[j])%p1,Y=((ll)Y*has2+s[j])%p2,Z=((ll)Z*has1+s1[j])%p1,W=((ll)W*has2+s1[j])%p2;
		if(mp.find({{X,Y},{Z,W}})==mp.end()) puts("0");
		else{
			ll u=rt[mp[{{X,Y},{Z,W}}]];ans=0;
			for(int j=0;j<s.size();j++){
				ll x=s[j]-'a';
				if(s[j]!=s1[j]) x=26;
				u=t[u].son[x];
				ans+=ed[u];
			}
			write(ans),putchar('\n'); 
		}
	}
	return 0;
}
