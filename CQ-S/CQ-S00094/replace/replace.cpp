#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int n,q; 
const int maxn=2e5+5;
const int maxnl=5e6+5;
char s1[maxn],s2[maxn];
const ull p=131;
ll ans[maxn];
map<ull,int> id;
int rt[maxn],tot;
int trie[maxnl][26],tt;
vector<ull> en[maxnl];
vector<int> as[maxnl];
vector<char> t1[maxn];
inline void Insert(int u,int l,ull sf){
	for(int i=l;i>=1;i--){
		if(!trie[u][s1[i]-'a']) trie[u][s1[i]-'a']=++tt;
		u=trie[u][s1[i]-'a'];
	}
	en[u].push_back(sf);
//	cout<<"add:"<<u<<" "<<sf<<endl;
}
inline void Insert_ask(int u,int l,int ij){
	for(int i=l;i>=1;i--){
		if(!trie[u][s1[i]-'a']) break;
		u=trie[u][s1[i]-'a'];
	}
	as[u].push_back(ij);
//	cout<<"add ask:"<<u<<" "<<ij<<endl;
}
unordered_map<ull,int> sum;
inline void solve(int x){
//	cout<<"go:"<<x<<endl;
	for(auto x:en[x]) sum[x]++;
	for(auto x:as[x]){
		ans[x]+=(ll)sum[0];
		ull hsh=0;
//		cout<<"ask:"<<x<<" "<<0<<endl;
		for(auto j:t1[x]){
			hsh=hsh*p+j;
//			cout<<"ask:"<<x<<" "<<hsh<<endl;
			ans[x]+=(ll)sum[hsh];
		}
	}
	for(int i=0;i<26;i++) if(trie[x][i]) solve(trie[x][i]);
	for(auto x:en[x]) sum[x]--;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1);
		int l=0,r=len+1;
		while(l<len && s1[l+1]==s2[l+1]) l++;
		while(r>1 && s1[r-1]==s2[r-1]) r--;
		if(l>r) continue;
		ull md=0,sf=0;
		for(int i=r;i<=len;i++) sf=sf*p+s1[i];
		for(int i=l+1;i<r;i++) md=md*p+s1[i];
		for(int i=l+1;i<r;i++) md=md*p+s2[i];
		if(!id[md]){
			id[md]=++tot;
			rt[tot]=++tt;
		}
//		cout<<l<<" "<<r<<" "<<md<<endl;
//		cout<<rt[id[md]]<<endl;
		Insert(rt[id[md]],l,sf);
	}
	for(int j=1;j<=q;j++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1);
		int len2=strlen(s2+1);
		if(len!=len2) continue;
		int l=0,r=len+1;
		while(l<len && s1[l+1]==s2[l+1]) l++;
		while(r>1 && s1[r-1]==s2[r-1]) r--;
		ull md=0,sf=0;
		for(int i=l+1;i<r;i++) md=md*p+s1[i];
		for(int i=l+1;i<r;i++) md=md*p+s2[i];
//		cout<<l<<" "<<r<<" "<<md<<endl;
		if(id.find(md)==id.end()) continue;
		for(int i=r;i<=len;i++) t1[j].push_back(s1[i]);
//		cout<<rt[id[md]]<<endl;
		Insert_ask(rt[id[md]],l,j);
	}
	for(int i=1;i<=tot;i++) solve(rt[i]);	
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	} 
	return 0;
}
/*
��������ѯ�ʡ�
��һ�������ֵ���������ѯ�� 
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
