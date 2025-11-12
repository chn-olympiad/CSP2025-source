#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,L=1e6+10;
inline int read(){
	int res=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch))
		flag=(ch=='-')?-1:1,
		ch=getchar();
	while(isdigit(ch))
		res=(res<<3)+(res<<1)+(ch^48),
		ch=getchar();
	return res*flag;
}
int n,q;
char ch,tl[L],tr[L];
vector<int> init=vector<int>(30,0);
vector<vector<int> > nodel;
vector<vector<int> > noder;
int lcnt,rcnt;
set<int> lend[L],rend[L];
int lm,rm;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=5;i++){	
		nodel.push_back(init);
		noder.push_back(init);
	}
	for(int siz,p=0,i=1;i<=n;i++){
		scanf("%s",tl+1);
		siz=strlen(tl+1);
		p=0;
		for(int cnt=1;cnt<=siz;cnt++){
			ch=tl[cnt];
			if(nodel[p][ch-'a']) p=nodel[p][ch-'a'];
			else{
				nodel.push_back(init);
				nodel[p][ch-'a']=++lcnt;
				p=lcnt;
			}
		}
		lend[p].insert(i);
		scanf("%s",tr+1);
		p=0;
		for(int cnt=1;cnt<=siz;cnt++){
			ch=tr[cnt];
			if(noder[p][ch-'a']) p=noder[p][ch-'a'];
			else{
				noder.push_back(init);
				noder[p][ch-'a']=++rcnt;
				p=rcnt;
			}
		}
		rend[p].insert(i);
	}
	while(q--){
		int siz,ans=0;
		scanf("%s%s",tl+1,tr+1);
		siz=strlen(tl+1);
		lm=0,rm=siz+1;
		for(int i=1;tl[i]==tr[i] and i<=siz;i++) lm=i;
		for(int i=siz;tl[i]==tr[i] and i>=1;i--) rm=i;
		for(int i=1;i<=siz;i++){
			if(i-1>lm) break; 
			for(int lp=0,rp=0,j=i;j<=siz;j++){
				if(nodel[lp][tl[j]-'a']) lp=nodel[lp][tl[j]-'a'];
				else break;
				if(noder[rp][tr[j]-'a']) rp=noder[rp][tr[j]-'a'];
				else break;
				for(auto x:lend[lp]){
					if(rend[rp].find(x)!=rend[rp].end() and j+1>=rm) ++ans;
				}
			}			
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
