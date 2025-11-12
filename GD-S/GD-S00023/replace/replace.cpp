#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e4+10;
const int maxm=2000+10;
char t1[maxn],t2[maxn];
int n,q;
int pos1[maxn],pos2[maxn];//每个可替换的kmp的j指针 
char s1[maxn][maxm],s2[maxn][maxm];
int nxt1[maxn][maxm],nxt2[maxn][maxm],s1len[maxn],s2len[maxn]; 
bool pre[maxn],suf[maxn];
void mian(){
	memset(pos1,0,sizeof(pos1));
	memset(pos2,0,sizeof(pos2));
	scanf(" %s %s",t1+1,t2+1); 
	int len=strlen(t1+1);
	int ans=0;
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	pre[0]=suf[len+1]=1;
	for(int i=1;i<=len;i++){
		pre[i]=pre[i-1]&(t1[i]==t2[i]);
	}
	for(int i=len;i>=1;i--){
		suf[i]=suf[i+1]&(t1[i]==t2[i]);
	}
	for(int i=1;i<=len;i++){
		for(int k=1;k<=n;k++){
			bool f1=0,f2=0;
			while(pos1[k]&&t1[i]!=s1[k][pos1[k]+1])
				pos1[k]=nxt1[k][pos1[k]];
			if(t1[i]==s1[k][pos1[k]+1])
				pos1[k]++;
			if(pos1[k]==s1len[k]){
				f1=1;
				pos1[k]=0;
			} 
			while(pos2[k]&&t2[i]!=s2[k][pos2[k]+1])
				pos2[k]=nxt2[k][pos2[k]];
			if(t2[i]==s2[k][pos2[k]+1])
				pos2[k]++;
			if(pos2[k]==s2len[k]){
				f2=1;
				pos2[k]=0;
				if(f1&&f2&&pre[i-s1len[k]]&&suf[i+1]){
					ans++;
				}
			}
		} 
	}
	printf("%d\n",ans); 
	return ;
}
void get_kmp(){
	for(int k=1;k<=n;k++){
		nxt1[k][1]=0;
		for(int i=2,j=0;i<=s1len[k];i++){
			while(j&&s1[k][i]!=s1[k][j+1])
				j=nxt1[k][j];
			if(s1[k][i]==s1[k][j+1])
				j++;
			nxt1[k][i]=j;
		}
		nxt2[k][1]=0;
		for(int i=2,j=0;i<=s2len[k];i++){
			while(j&&s2[k][i]!=s2[k][j+1])
				j=nxt2[k][j];
			if(s2[k][i]==s2[k][j+1])
				j++;
			nxt2[k][i]=j;
		}
	} 
}
int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("  %s",s1[i]+1);
		scanf("  %s",s2[i]+1);
		s1len[i]=strlen(s1[i]+1);
		s2len[i]=strlen(s2[i]+1);
	} 
	get_kmp();
	while(q--){
		mian();
	}
	return 0; 
}

