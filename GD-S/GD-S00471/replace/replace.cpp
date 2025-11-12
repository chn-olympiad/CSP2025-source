#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,len[200005],l;
ll ans=0;
unsigned long long h1[1000006],h2[1000006],ha[200005],hb[200005],p[1000006],sp;
string s,t;
ll asn[200005];
ll mp[7000006];
ll tot,fail[1000006],to[1000006][30],ff[1000006],tb[1000006][30],tt;
vector<ll>tr[1000006],tp[1000006];
void insert(ll id){
	ll now=0;
	for(int i=0;i<len[id];i++){
		if(!to[now][s[i]-'a']) to[now][s[i]-'a']=++tot;
		now=to[now][s[i]-'a'];
	}
	tr[now].push_back(id);
}
void ss(ll id){
	ll now=0;
	for(int i=0;i<len[id];i++){
		if(!tb[now][s[i]-'a']) tb[now][s[i]-'a']=++tt;
		now=tb[now][s[i]-'a'];
	}
	tp[now].push_back(id);
}
queue<ll>qs;
void build(){
	for(int i=0;i<=25;i++) if(to[0][i]) qs.push(to[0][i]);
	while(!qs.empty()){
		ll now=qs.front();
		qs.pop();
		for(int i=0;i<=25;i++) if(to[now][i]) fail[to[now][i]]=to[fail[now]][i],qs.push(to[now][i]);
		else to[now][i]=to[fail[now]][i];
	}
	for(int i=0;i<=25;i++) if(tb[0][i]) qs.push(tb[0][i]);
	while(!qs.empty()){
		ll now=qs.front();
		qs.pop();
		for(int i=0;i<=25;i++) if(tb[now][i]) ff[tb[now][i]]=tb[ff[now]][i],qs.push(tb[now][i]);
		else tb[now][i]=tb[ff[now]][i];
	}
}
set<ll>st;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=1000000;i++)p[i]=p[i-1]*1331;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s;
		len[i]=s.length();
		insert(i);
		for(int j=0;j<len[i];j++) ha[i]=ha[i]*1331+s[j]-'a'+1,sp+=(s[j]=='b');
		cin>>s;
		ss(i);
		for(int j=0;j<len[i];j++) hb[i]=hb[i]*1331+s[j]-'a'+1,sp+=(s[j]=='b');
	}
	if(q==1||n>1000){
		build();
		for(int i=1;i<=q;i++){
			cin>>s>>t;
			l=s.length();
			ans=0;
			for(int i=0;i<l;i++)
			h1[i+1]=h1[i]*1331+s[i]-'a'+1,h2[i+1]=h2[i]*1331+t[i]-'a'+1;
			ll x=0,y=0,ra,rb;
			for(int j=0;j<l;j++){
				x=to[x][s[j]-'a'];
				y=tb[y][t[j]-'a'];
				if(h1[l]-h1[j+1]*p[l-j-1]!=h2[l]-h2[j+1]*p[l-j-1]) continue;
				ra=x;
				rb=y;
				st.clear();
				while(ra){
					if(!tr[ra].empty()) for(auto o:tr[ra]) 
					st.insert(o);
					ra=fail[ra];
				}
				while(rb){
					if(!tp[rb].empty()) for(auto o:tp[rb]) 
					if(st.find(o)!=st.end()&&h1[j+1-len[o]]==h2[j+1-len[o]]) ans++;
					rb=ff[rb];
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(q--){
		cin>>s>>t;
		ans=0;
		l=s.length();
		for(int i=0;i<l;i++)
		h1[i+1]=h1[i]*1331+s[i]-'a'+1,h2[i+1]=h2[i]*1331+t[i]-'a'+1;
		for(int i=1;i<=l;i++){
			if(h1[i-1]==h2[i-1])
			for(int j=1;j<=n;j++)
			if(i+len[j]-1<=l&&h1[l]-h1[i+len[j]-1]*p[l+1-i-len[j]]==h2[l]-h2[i+len[j]-1]*p[l+1-i-len[j]]&&h1[i+len[j]-1]-h1[i-1]*p[len[j]]==ha[j]&&h2[i+len[j]-1]-h2[i-1]*p[len[j]]==hb[j]) ans++;
		}
		cout<<ans<<"\n";
	}
}
