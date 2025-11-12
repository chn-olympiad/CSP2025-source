#include<bits/stdc++.h>
using namespace std;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=2e5;
	const int M=5e6;
	const int INF=2e9;
	const LL Base1=64,Base2=729;
	const LL Mod1=998244353,Mod2=1e9+7;
	struct Hash{
		LL val1,val2;
		bool operator ==(const Hash& A)const{
			return val1==A.val1&&val2==A.val2;
		}
		bool operator <(const Hash& A)const{
			if(val1!=A.val1) return val1<A.val1;
			return val2<A.val2;
		}
		void operator +=(const char& A){
			val1=(val1*Base1+A)%Mod1;
			val2=(val2*Base2+A)%Mod2;
		}
	};
	typedef pair<Hash,Hash> PHH;
	typedef pair<PHH,int> PPI;
	int n,Q,ans[N+5];
	struct string_pair{
		string p,q,str;
		int siz,fdif,ldif;
		Hash dhp,dhq;
		void init(){
			cin>>p>>q;
			if(p.size()!=q.size()){
				siz=-1;
				return;
			}
			siz=p.size();
			fdif=ldif=-1;
			for(int i=0;i<siz;i++){
				if(p[i]!=q[i]){
					if(fdif==-1) fdif=i;
					ldif=i;
				}
			}
			if(fdif==-1) return;
			for(int i=fdif;i<=ldif;i++){
				dhp+=p[i];
				dhq+=q[i];
			}
		}
		void init_str(){
			for(int i=0;i<fdif;i++) str+=p[i];
			str+='{';
			for(int i=ldif+1;i<siz;i++) str+=q[i];
		}
	}s[N+5],t[N+5];
	int pcnt,li[2*N+5];
	PPI p[2*N+5];
	int iecnt;
	struct Trie{
		int son[27],num,fail,nxt[27];
		void clear(){
			for(int j=0;j<27;j++){
				son[j]=0;
				nxt[j]=0;
			}
			num=0;
			fail=0;
		}
	}Tree[M+5];
	void Insert(string& str){
		int rt=0,id;
		for(auto u:str){
			id=u-'a';
			if(!Tree[rt].son[id]){
				Tree[rt].son[id]=++iecnt;
				Tree[iecnt].clear();
			}
			rt=Tree[rt].son[id];
		}
		Tree[rt].num++;
	}
	queue<int> qu;
	void Build(){
		qu.push(0);
		int rt;
		while(!qu.empty()){
			rt=qu.front();
			qu.pop();
			for(int j=0;j<27;j++){
				if(Tree[rt].son[j]){
					Tree[Tree[rt].son[j]].fail=Tree[Tree[rt].fail].nxt[j];
					Tree[rt].nxt[j]=Tree[rt].son[j];
					qu.push(Tree[rt].son[j]);
				}
				else Tree[rt].nxt[j]=Tree[Tree[rt].fail].nxt[j];
			}
			Tree[rt].num+=Tree[Tree[rt].fail].num;
		}
	}
	int Getans(string& str){
		int rt=0,rtn=0;
		for(auto u:str){
			rt=Tree[rt].nxt[u-'a'];
			rtn+=Tree[rt].num;
		}
		return rtn;
	}
	void Solve(int L,int R){
		if(p[L].sec>0||p[R].sec<0) return;
		int mid=L;
		for(int i=L;i<=R;i++){
			if(p[i].sec<0){
				mid=i;
				s[-p[i].sec].init_str();
				li[i]=-p[i].sec;
			}
			else{
				t[p[i].sec].init_str();
				li[i]=p[i].sec;
			}
		}
		iecnt=0;
		Tree[0].clear();
		for(int i=L;i<=mid;i++){
			Insert(s[li[i]].str);
		}
		Build();
		for(int i=mid+1;i<=R;i++){
			ans[li[i]]=Getans(t[li[i]].str);
		}
	}
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>n>>Q;
		for(int i=1;i<=n;i++){
			s[i].init();
			if(s[i].fdif==-1) continue;
			p[++pcnt]={{s[i].dhp,s[i].dhq},-i};
		}
		for(int i=1;i<=Q;i++){
			t[i].init();
			if(t[i].siz==-1) continue;
			p[++pcnt]={{t[i].dhp,t[i].dhq},i};
		}
		sort(p+1,p+pcnt+1);
		for(int i=1,j=1;i<=pcnt;i=j+1){
			while(j<pcnt&&p[j+1].fir==p[i].fir) j++;
			Solve(i,j);
		}
		for(int i=1;i<=Q;i++){
			cout<<ans[i]<<"\n";
		}
		return 0;
	}
}
int main(){
	cs::main();
	return 0;
}
/*
把问题规约成了：给定一些模式串，多次询问，每次给一个字符串，求前面给出的模式串中有几个是这个串的子串 
但 AC 自动机不是超纲内容吗？？？ 
 AC 自动机复杂度不是 O(SV) 的吗？怎么极限数据跑这么快 
多么伟大啊 AC 自动机，我对您的敬仰之情如洪水泛滥，又如黄河流水，连绵不绝。后面忘了。 
154min 写完 T3 
*/
