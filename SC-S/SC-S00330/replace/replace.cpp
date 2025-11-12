#include<bits/stdc++.h>
#define N 2000010
using namespace std;
int n,q,ans(0),targ;
string s1[N],s2[N],q1,q2;
int dire[N][30],cnt;
vector<int> towar[N];
void add(int x,int id,int xb,int siz){
	if(xb==siz){
		towar[x].push_back(id);
		return void();
	}
	if(!dire[x][s1[id][xb]-'a']){
		dire[x][s1[id][xb]-'a']=++cnt;
	}
	add(dire[x][s1[id][xb]-'a'],id,xb+1,siz);
}
void tofind(int x,int flen,int begi){
//	cout<<x<<" "<<flen<<" "<<begi<<"\n";
	if(flen>=targ-begi+1){
		for(int i=0;i<towar[x].size();++i){
//			cout<<s2[towar[x][i]]<<" "<<q2.substr(begi,flen)<<"\n";
			if(s2[towar[x][i]]==q2.substr(begi,flen))++ans;
		}
	}
	if(dire[x][q1[begi+flen]-'a']){
		tofind(dire[x][q1[begi+flen]-'a'],flen+1,begi);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		add(0,i,0,s1[i].size());
	}
	for(int i=1;i<=q;++i){
		int slen,st=-1,ed=0;
		ans=0;
		cin>>q1>>q2;
		slen=q1.size();
		for(int j=0;j<slen;++j){
			if(q1[j]!=q2[j]){
				if(st==-1)st=j;
				ed=j;
				int lent=1;
				while(q1[j+lent]!=q2[j+lent]&&lent+j<slen)++lent;
				ed=j+lent-1;
			}
		}
		targ=ed;
//		cout<<st<<" "<<ed<<'\n';
		for(int i=st;i>=0;--i){
			tofind(0,0,i);
//			cout<<i<<" "<<ans<<"\n";
		}
		cout<<ans<<'\n';
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
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/