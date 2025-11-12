#include<bits/stdc++.h>
using namespace std;
#define LEN 1000010

long long read(){
	long long res=0;char c=getchar();bool flag=0;
	while(c<'0'||c>'9'){
		flag|=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<3)+(c^48);
		c=getchar();
	}
	return res * ( flag ? -1 : 1 );
}

int n,q;
int trie1[LEN][26],trie2[LEN][26];
vector<int> exist1[LEN],exist2[LEN];
int cnt1,cnt2;


void insert(string s,string t,int id){
	int p=0,len=s.size();
	for(int i=0;i<len;i++){
		if(!trie1[p][s[i]-'a']) trie1[p][s[i]-'a']=++cnt1;
		p=trie1[p][s[i]-'a'];
	}
	exist1[p].push_back(id);
	p=0;len=t.size();
	for(int i=0;i<len;i++){
		if(!trie2[p][t[i]-'a']) trie2[p][t[i]-'a']=++cnt2;
		p=trie2[p][t[i]-'a'];
	}
	exist2[p].push_back(id);
}

int query(string s,string t,int st){
	map<int,bool> mp;
	int res=0;
	int p1=0,p2=0,len=s.size();
	int flag=0,i;
	for(i=st;i<len;i++){
		if(flag==0&&s[i]!=t[i]) flag++;
		if(flag==1&&s[i]==t[i]) flag++;
		if(flag==2){
			for(int j=0;j<exist1[p1].size();j++) mp[exist1[p1][j]]=1;
			for(int j=0;j<exist2[p2].size();j++) res+=(mp[exist2[p2][j]]==1);
		}
		if(trie1[p1][s[i]-'a']==0) break;
		if(trie2[p2][t[i]-'a']==0) break;
		p1=trie1[p1][s[i]-'a'];
		p2=trie2[p2][t[i]-'a'];
	}
	if(i==len){
		for(int j=0;j<exist1[p1].size();j++) mp[exist1[p1][j]]=1;
		for(int j=0;j<exist2[p2].size();j++) res+=(mp[exist2[p2][j]]==1);
	}
	return res;
}

void Cecilia(){
	n=read();q=read();
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		insert(s,t,i);
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		int len=s.size();
		int ans=0;
		for(int st=0;st<len;st++){
			if(st>0) if(s[st-1]!=t[st-1]) break;
			ans+=query(s,t,st);
		}
		printf("%d\n",ans);
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Cecilia();
	return 0;
}

