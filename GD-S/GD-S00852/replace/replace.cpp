#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull base=47;
int n,q,ct;
ull rnd[27],pw[5000005];
struct tri{
	int son[26];
	vector<ull> v;
}tr[5000005];
vector<ull> V,V2,cle,ac;
struct trie{
	int rt;
	void insert(string t,ull val){
		if(!rt) rt=++ct;
		int now=rt,len=t.length()-1;
//		cout<<
		for(int i=1;i<=len;i++){
			int x=t[i]-'a';
			if(!tr[now].son[x]) tr[now].son[x]=++ct;
			now=tr[now].son[x];
		}
		tr[now].v.push_back(val);
	}
	void find(string t){
		if(!rt) return;
//		cout<<t<<" "<<t.length()<<endl;
		int now=rt,len=t.length()-1;
		for(int i=1;i<=len;i++){
			int x=t[i]-'a';
			for(auto Val:tr[now].v) V2.push_back(Val);
			if(!tr[now].son[x]) return;
			now=tr[now].son[x];
		}
		for(auto Val:tr[now].v) V2.push_back(Val);
	}
};
map<ull,trie> mp;
void solve(ull val,string t){
	V2=cle,mp[val].find(t);
	sort(V2.begin(),V2.end()),sort(V.begin(),V.end());
	int now=0,len=V2.size();
	int cnt=0;
	for(auto x:V){
		while(now<len&&V2[now]<x) now++;
		if(now==len) break;
		while(now<len&&V2[now]==x) cnt++,now++;
		if(now==len) break;
	}
	printf("%d\n",cnt);
}
mt19937_64 myrand(time(0));
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=0;i<26;i++) rnd[i]=myrand();
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*base;
	scanf("%d%d",&n,&q);
	for(int Smart=1;Smart<=n;Smart++){
		string s0,s1;
		cin>>s0>>s1;
		if(s0==s1) continue;
		int ld,rd,len=s1.length();
		ld=len+1,rd=0,s1=' '+s1,s0=' '+s0;
		for(int i=1;i<=len;i++){
			if(s1[i]!=s0[i]){
				ld=i;
				break;
			}
		}
		for(int i=len;i>=1;i--){
			if(s1[i]!=s0[i]){
				rd=i;
				break;
			}
		}
		ull val=0;
		int cnt=0;
		for(int i=ld;i<=rd;i++){
			val=val+pw[cnt]*rnd[s0[i]-'a']+pw[cnt+1]*rnd[s1[i]-'a'];
			cnt+=2;
		}
//		printf("%d %d\n",ld,rd);
		string t=" ";
		for(int i=ld-1;i>=1;i--) t=t+s0[i];
		ull val2=0;
		cnt=0;
		for(int i=rd+1;i<=len;i++) val2=val2+pw[cnt]*rnd[s0[i]-'a'],cnt++;
//		cout<<val<<" "<<val2<<endl;
		mp[val].insert(t,val2);
	}
//	printf("%d ",ct);
	for(int Smart=1;Smart<=q;Smart++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			printf("0\n");
			continue;
		}
		int ld=0,rd=0,len=t1.length();
		ld=len+1,t1=' '+t1,t2=' '+t2;
		for(int i=1;i<=len;i++){
			if(t1[i]!=t2[i]){
				ld=i;
				break;
			}
		}
		for(int i=len;i>=1;i--){
			if(t2[i]!=t1[i]){
				rd=i;
				break;
			}
		}
		ull val=0;
		int cnt=0;
		for(int i=ld;i<=rd;i++){
			val=val+pw[cnt]*rnd[t1[i]-'a']+pw[cnt+1]*rnd[t2[i]-'a'];
			cnt+=2;
		}
		string t=" ";
		for(int i=ld-1;i>=1;i--) t=t+t1[i];
		ull val2=0;
		cnt=0;
		V=cle;
		V.push_back(0);
		for(int i=rd+1;i<=len;i++){
			val2=val2+pw[cnt]*rnd[t1[i]-'a'],cnt++;
			V.push_back(val2);
		}
		solve(val,t);
	}
	return 0;
}
