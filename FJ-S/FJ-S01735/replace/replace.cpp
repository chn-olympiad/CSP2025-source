#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}

const int L=5e6+10,N=2e5+10;
int n,q;
string s1,s2;

int cnt;
unordered_map<string,int> mp;
int rt1[N],rt2[N];
vector<int> tmp;
bool flag[N];

struct Trie{
	int tot;
	struct tree{
		int son[26];
		vector<int> v;
	}tr[L];
	void new_rt(int id){
		rt1[id]=++tot,rt2[id]=++tot;
	}
	void insert(string s,int root,int id){
		int m=s.size();
		int p=root;
		for(int i=0;i<m;i++){
			int u=s[i]-'a';
			if(!tr[p].son[u])tr[p].son[u]=++tot;
			p=tr[p].son[u];
		}
		tr[p].v.push_back(id);
	}
	int find(string s,int root,int tp){
		int ans=0;
		int m=s.size();
		int p=root;
		for(int i=0;i<m;i++){
			for(int j=0;j<tr[p].v.size();j++){
				if(tp==0){
					flag[tr[p].v[j]]=1;
					tmp.push_back(tr[p].v[j]);	
				}
				if(tp==1){
					if(flag[tr[p].v[j]])ans++;
				}
			}
			int u=s[i]-'a';
			if(!tr[p].son[u])return ans;
			else p=tr[p].son[u];
		}
		for(int j=0;j<tr[p].v.size();j++){
			if(tp==0){
				flag[tr[p].v[j]]=1;
				tmp.push_back(tr[p].v[j]);	
			}
			if(tp==1){
				if(flag[tr[p].v[j]])ans++;
			}
		}
		return ans;
	}
}Tree;

signed main(){
	
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		if(s1==s2)continue;
		int len=s1.size();
		string pre,suf,es1,es2,es;
		int l,r;
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		for(int j=l;j<=r;j++)es1+=s1[j],es2+=s2[j];
		es=es1+es2;
		if(!mp[es]){
			mp[es]=++cnt;
			Tree.new_rt(mp[es]);
		}
		for(int j=l-1;j>=0;j--)pre+=s1[j];
		for(int j=r+1;j<len;j++)suf+=s1[j];
		Tree.insert(pre,rt1[mp[es]],i);
		Tree.insert(suf,rt2[mp[es]],i);
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int len=s1.size();
		string pre,suf,es1,es2,es;
		int l,r;
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		for(int j=l;j<=r;j++)es1+=s1[j],es2+=s2[j];
		es=es1+es2;
		if(!mp[es]){
			write(0);
			putchar('\n');
			continue;
		}
		for(int j=l-1;j>=0;j--)pre+=s1[j];
		for(int j=r+1;j<len;j++)suf+=s1[j];
		Tree.find(pre,rt1[mp[es]],0);
		int ans=Tree.find(suf,rt2[mp[es]],1);
		for(int j=0;j<tmp.size();j++){
			flag[tmp[j]]=0;
		}
		tmp.clear();
		write(ans);
		putchar('\n');
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/