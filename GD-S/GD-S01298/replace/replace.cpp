#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <queue>
using namespace std;

void read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!('0'<=c && c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
int dtrie[6000010][27],nxt[6000010],val[6000010],dc=0;
int strie[6000010][27],rts[6000010],sc=0;
int dq[6000010],hd,tl;
void build(int rt){
	hd=1;
	tl=0;
	nxt[rt]=rt;
	for(int i=0;i<=26;i++){
		if(dtrie[rt][i]){
			dq[++tl]=dtrie[rt][i];
			nxt[dtrie[rt][i]]=rt;
		}else{
			dtrie[rt][i]=rt;
		}
	}
	while(hd<=tl){
		int f=dq[hd++];
		val[f]+=val[nxt[f]];
		for(int i=0;i<=26;i++){
			if(dtrie[f][i]){
				nxt[dtrie[f][i]]=dtrie[nxt[f]][i];
				dq[++tl]=dtrie[f][i];
			}else{
				dtrie[f][i]=dtrie[nxt[f]][i];
			}
		}
	}
}
int n,q;
char s1[5000010],s2[5000010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);
	read(q);
	for(int i=1;i<=n;i++){
		scanf(" %s %s",s1+1,s2+1);
		int prf=-1,suf,l=strlen(s1+1);
		for(int j=1;j<=l;j++){
			if(s1[j]!=s2[j]){
				prf=j-1;
				break;
			}
		}
		if(prf==-1){
			continue;
		}
		for(int j=1;j<=l;j++){
			if(s1[j]!=s2[j]){
				suf=j+1;
			}
		}
		int cur=0;
		for(int j=prf+1;j<suf;j++){
			if(!strie[cur][s1[j]-'a']){
				strie[cur][s1[j]-'a']=++sc;
			}
			cur=strie[cur][s1[j]-'a'];
		}
		if(!strie[cur][26]){
			strie[cur][26]=++sc;
		}
		cur=strie[cur][26];
		for(int j=prf+1;j<suf;j++){
			if(!strie[cur][s2[j]-'a']){
				strie[cur][s2[j]-'a']=++sc;
			}
			cur=strie[cur][s2[j]-'a'];
		}
		if(!rts[cur]){
			rts[cur]=++dc;
		}
		cur=rts[cur];
		for(int j=1;j<=prf;j++){
			if(!dtrie[cur][s1[j]-'a']){
				dtrie[cur][s1[j]-'a']=++dc;
			}
			cur=dtrie[cur][s1[j]-'a'];
			//printf("[%lld]",cur);
		}
		//printf("[%lld]",dtrie[cur][26]);
		if(!dtrie[cur][26]){
			dtrie[cur][26]=++dc;
		}
		cur=dtrie[cur][26];
		for(int j=suf;j<=l;j++){
			if(!dtrie[cur][s1[j]-'a']){
				dtrie[cur][s1[j]-'a']=++dc;
			}
			cur=dtrie[cur][s1[j]-'a'];
		}
		val[cur]++;
	}
	for(int i=1;i<=sc;i++){
		if(rts[i]){
			build(rts[i]);
		}
	}
	while(q--){
		scanf(" %s %s",s1+1,s2+1);
		int l=strlen(s1+1),res=0;
		if(strlen(s2+1)!=l){
			printf("0\n");
			continue;
		}
		int prf=-1,suf;
		for(int j=1;j<=l;j++){
			if(s1[j]!=s2[j]){
				prf=j-1;
				break;
			}
		}
		for(int j=1;j<=l;j++){
			if(s1[j]!=s2[j]){
				suf=j+1;
			}
		}
		int cur=0;
		for(int j=prf+1;j<suf;j++){
			if(!strie[cur][s1[j]-'a']){
				goto die;
			}
			cur=strie[cur][s1[j]-'a'];
		}
		if(!strie[cur][26]){
			goto die;
		}
		cur=strie[cur][26];
		for(int j=prf+1;j<suf;j++){
			if(!strie[cur][s2[j]-'a']){
				goto die;
			}
			cur=strie[cur][s2[j]-'a'];
		}
		if(!rts[cur]){
			goto die;
		}
		cur=rts[cur];
		for(int j=1;j<=prf;j++){
			cur=dtrie[cur][s1[j]-'a'];
			res+=val[cur];
		}
		cur=dtrie[cur][26];
		res+=val[cur];
		for(int j=suf;j<=l;j++){
			cur=dtrie[cur][s1[j]-'a'];
			res+=val[cur];
		}
		die:;
		printf("%d\n",res);
	}
	return 0;
}
