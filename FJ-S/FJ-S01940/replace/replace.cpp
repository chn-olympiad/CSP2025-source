#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=5e6+10;
const long long p=998244353;
const long long k=251;//orz 251Sec %%%
bool Mbe;

int tr[M][27];
int fail[M],cnt;
int root[N],val[M],res,siz[N];
unordered_map<long long,int>mp;//Magical ds power

void insert(int id,string s){
	int u=root[id]; siz[id]++;
	for(int i=0;i<s.size();i++){
		int v=s[i]-'a'+1;
		if(!tr[u][v]) tr[u][v]=++cnt;
		u=tr[u][v];
	}
	val[u]++;
}

void build(int id){
	queue<int>q; int rt=root[id];
	fail[rt]=rt;
	for(int i=0;i<=26;i++){
		if(tr[rt][i]){
			q.push(tr[rt][i]);
			fail[tr[rt][i]]=rt;
		}else tr[rt][i]=rt;
	}
	
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<=26;i++){
			if(!tr[u][i]){
				tr[u][i]=tr[fail[u]][i];
			}else{
				fail[tr[u][i]]=tr[fail[u]][i];
				q.push(tr[u][i]);
			}
		}
		val[u]+=val[fail[u]];
	}
}

void fake_main(){
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2; cin>>s1>>s2;
		int l=-1,r=-1;
		for(int j=0;j<s1.size();j++){
			if(l==-1&&s1[j]!=s2[j]) l=j;
			if(s1[j]!=s2[j]) r=j;
		}
		
		long long sum1=0,sum2=0;
		long long sum;
		for(int j=l;j<=r;j++){
			sum1=sum1*k%p;
			sum1=(sum1+s1[j])%p;
		}
		for(int j=l;j<=r;j++){
			sum2=sum2*k%p;
			sum2=(sum2+s2[j])%p;
		}
		sum=sum1*p+sum2;
		
		if(!mp[sum]){
			mp[sum]=++res;
			root[res]=++cnt;
		}
		
		string s;
		for(int j=0;j<l;j++) s.push_back(s1[j]);
		s.push_back('`');//it means a-1
		for(int j=r+1;j<s1.size();j++) s.push_back(s1[j]);
		insert(mp[sum],s);
	}
	
	for(int i=1;i<=res;i++) build(i);
	
	for(int i=1;i<=q;i++){
		string s1,s2; cin>>s1>>s2;
		int l=-1,r=-1;
		for(int j=0;j<s1.size();j++){
			if(l==-1&&s1[j]!=s2[j]) l=j;
			if(s1[j]!=s2[j]) r=j;
		}
		
		long long sum1=0,sum2=0;
		long long sum;
		for(int j=l;j<=r;j++){
			sum1=sum1*k%p;
			sum1=(sum1+s1[j])%p;
		}
		for(int j=l;j<=r;j++){
			sum2=sum2*k%p;
			sum2=(sum2+s2[j])%p;
		}
		sum=sum1*p+sum2;
		
		
		if(!mp[sum]||s1.size()!=s2.size()){
			cout<<"0\n"; continue;//no ori-equal replaces. just output 0
		}
		string s;
		for(int j=0;j<l;j++) s.push_back(s1[j]);
		s.push_back('`');//it means a-1
		for(int j=r+1;j<s1.size();j++) s.push_back(s1[j]);
		//then use "s" to run the acam.
		
		int ans=0,u=root[mp[sum]];
		for(int i=0;i<s.size();i++){
			int v=s[i]-'a'+1; //cout<<u<<"\n";
			u=tr[u][v]; ans+=val[u];//calc answers.
		}
		cout<<ans<<"\n";
	}
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2 1
xabcx xadex
bc de
xabcx xadex
*/

bool Med;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cerr<<fabs(&Med-&Mbe)/1028576.0<<"MB\n";
	int t; t=1;
	while(t--) fake_main();
	cerr<<clock()*1.0/CLOCKS_PER_SEC*1000.0<<"ms\n";
}

