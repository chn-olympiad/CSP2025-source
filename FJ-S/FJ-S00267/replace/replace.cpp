#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5,M=2e6+5;
int t,n,q,ans[N];
int ch1[M][27],tot1=1,len;
int ch2[M][27];
int ch3[M][27]; bool vis[M];
bitset<40005> b[40005],qwq;
char s1[M],s2[M];
int head2[M],id2[N],nxt2[N],tot2;
int head3[M],id3[N],nxt3[N],tot3;
int head4[M],id4[N],nxt4[N],tot4;
int head5[M],id5[N],nxt5[N],tot5;
void ins2(int x,int y){++tot2;id2[tot2]=y;nxt2[tot2]=head2[x];head2[x]=tot2;}
void ins3(int x,int y){++tot3;id3[tot3]=y;nxt3[tot3]=head3[x];head3[x]=tot3;}
void ins4(int x,int y){++tot4;id4[tot4]=y;nxt4[tot4]=head4[x];head4[x]=tot4;}
void ins5(int x,int y){++tot5;id5[tot5]=y;nxt5[tot5]=head5[x];head5[x]=tot5;}
void dfs2(int x){
	for(int i=head2[x];i;i=nxt2[i]) qwq[id2[i]]=1;
	for(int i=head4[x];i;i=nxt4[i]) b[id4[i]]=b[id4[i]]&qwq;
	
	for(int i=0;i<26;i++) if(ch2[x][i]) dfs2(ch2[x][i]);
	for(int i=head2[x];i;i=nxt2[i]) qwq[id2[i]]=0;
}
void dfs3(int x){
	for(int i=head3[x];i;i=nxt3[i]) qwq[id3[i]]=1;
	for(int i=head5[x];i;i=nxt5[i]) b[id5[i]]=b[id5[i]]&qwq;
	
	for(int i=0;i<26;i++) if(ch3[x][i]) dfs3(ch3[x][i]);
	for(int i=head3[x];i;i=nxt3[i]) qwq[id3[i]]=0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
//	freopen("replace5.in","r",stdin);
//	freopen("replace5.out","w",stdout);
	scanf("%d%d",&n,&q);
	if((n>40000)||(q>40000)){
		while(q--) printf("0\n");
		return 0;}
	for(int i=1,p1,p2,u,now,c;i<=n;i++){
		p1=p2=0,u=1;
		scanf("%s%s",s1+1,s2+1); len=strlen(s1+1);
		for(int j=1;j<=len;j++) if(s1[j]!=s2[j]){p1=j;break;}
		for(int j=len;j>=1;j--) if(s1[j]!=s2[j]){p2=j;break;}
		if(!p1) continue;
		for(int j=p1;j<=p2;j++){
			c=s1[j]-'a';
			if(!ch1[u][c]) ch1[u][c]=++tot1;
			u=ch1[u][c];}
		for(int j=p1;j<=p2;j++){
			c=s2[j]-'a';
			if(!ch1[u][c]) ch1[u][c]=++tot1;
			u=ch1[u][c];}
		vis[u]=1;
		
		now=u;
		for(int j=p1-1;j>=1;j--){
			c=s1[j]-'a';
			if(!ch2[now][c]) ch2[now][c]=++tot1;
			now=ch2[now][c];}
		ins2(now,i);
		now=u;
		for(int j=p2+1;j<=len;j++){
			c=s1[j]-'a';
			if(!ch3[now][c]) ch3[now][c]=++tot1;
			now=ch3[now][c];}
		ins3(now,i);}
	
	for(int i=1,p1,p2,u,now,c,las;i<=q;i++){
		p1=p2=0,u=1;
		scanf("%s%s",s1+1,s2+1); len=strlen(s1+1);
		for(int j=1;j<=len;j++) if(s1[j]!=s2[j]){p1=j;break;}
		for(int j=len;j>=1;j--) if(s1[j]!=s2[j]){p2=j;break;}
		if(!p1) continue;
		for(int j=p1;j<=p2;j++){c=s1[j]-'a';u=ch1[u][c];}
		for(int j=p1;j<=p2;j++){c=s2[j]-'a';u=ch1[u][c];}
		if(!u) continue;
		if(!vis[u]) continue;
		las=now=u;
		for(int j=p1-1;j>=1;j--){
			c=s1[j]-'a';
			now=ch2[now][c];
			if(now) las=now;}
		ins4(las,i);
		
		
		las=now=u;
		for(int j=p2+1;j<=len;j++){
			c=s1[j]-'a';
			now=ch3[now][c];
			if(now) las=now;}
		ins5(las,i);
		
		b[i].set();
	}
	
	for(int i=1;i<=tot1;i++) if(vis[i]){
		dfs2(i);
		dfs3(i);}
	
	for(int i=1;i<=q;i++) printf("%d\n",(int)b[i].count());
	return 0;}



/*



4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb







*/





