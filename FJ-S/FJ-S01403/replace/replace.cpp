#include<bits/stdc++.h>
const int mod1=1e9+7;
const int mod2=1e9+9;
struct node{
	int h1,h2,res;
};
int n,q,trie[2500005][26],fail[2500005],cnt,hash1[200005],hash2[200005],resr[200005];
int ans[200005];
struct qy{
	int h1,h2,res,id;
};
std::vector<int> v[2500005],sta[2500005];
std::vector<qy> qry[2500005];
std::map<std::pair<int,std::pair<int,int> >,int> ma;
void insert(std::string t,int id){
	int len=t.size(),u=0;
	for(int i=0;i<len;i++){
		int opt=t[i]-'a';
		if(!trie[u][opt]) trie[u][opt]=++cnt;
		u=trie[u][opt];
	}
	sta[u].push_back(id);
}
void build(){
	std::queue<int> q;
	for(int i=0;i<26;i++){
		if(trie[0][i]) q.push(trie[0][i]);
	} 
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(trie[u][i]){
				fail[trie[u][i]]=trie[fail[u]][i];
				q.push(trie[u][i]);
			}
			else trie[u][i]=trie[fail[u]][i];
		}
	}
}
node getval(std::string s1,std::string s2){
	node val;
	int l=-1,r=-1;
	int len=s1.size();
	for(int j=0;j<len;j++){
		if(s1[j]!=s2[j]){
			r=j;
			if(l<0) l=j;
		}
	}
	if(l<0){
		val={0,0,0};
	}
	else{
		int now1=0,now2=0;
		for(int i=l;i<=r;i++){
			now1=(1ll*now1*131+s1[i])%mod1;
			now2=(1ll*now2*131+s1[i])%mod2;
		}
		now1=(1ll*now1*131+127)%mod1;
		now2=(1ll*now2*131+127)%mod2;
		for(int i=l;i<=r;i++){
			now1=(1ll*now1*131+s2[i])%mod1;
			now2=(1ll*now2*131+s2[i])%mod2;
		}
		val={now1,now2,len-1-r};
	}
	return val;
}
void query(std::string t,int id,node val){
	int len=t.size();
	int u=0;
	for(int i=0;i<len;i++){
		int opt=t[i]-'a';
		u=trie[u][opt];
		if(len-1-i<=val.res){
			qry[u].push_back({val.h1,val.h2,val.res-(len-1-i),id});
		}
	}
}
void dfs(int u){
	for(auto i:sta[u]){
//		printf("f:%d %d %d %d\n",u,val.h1,val.h2,val.res);
		std::pair<int,int> val={hash2[i],resr[i]};
		std::pair<int,std::pair<int,int> > nowval={hash1[i],val};
		ma[nowval]++;
	}
	for(auto i:qry[u]){
//		printf("g:%d %d %d %d\n",u,val.h1,val.h2,val.res);
		std::pair<int,int> val={i.h2,i.res};
		std::pair<int,std::pair<int,int> > nowval={i.h1,val};
		ans[i.id]+=ma[nowval];
//		printf("h:%d\n",ma[nowval]);
	}
	for(auto i:v[u]) dfs(i);
	for(auto i:sta[u]){
		std::pair<int,int> val={hash2[i],resr[i]};
		std::pair<int,std::pair<int,int> > nowval={hash1[i],val};
		ma[nowval]--;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		std::string s1,s2;
		std::cin>>s1>>s2;
		insert(s1,i);
		node val=getval(s1,s2);
		hash1[i]=val.h1,hash2[i]=val.h2,resr[i]=val.res;
	}
	build();
	for(int i=1;i<=cnt;i++) v[fail[i]].push_back(i);
	for(int i=1;i<=q;i++){
		std::string s1,s2;
		std::cin>>s1>>s2;
		node val=getval(s1,s2);
		query(s1,i,val);
	}
	dfs(0);
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
} 
