#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,L=5e6+5;
const ull p=131;
int n,k,ln[N],ans,l,r,m,lst[27],nxt[N],cnt[27],Mx,ch;
char S[L],T[2][L];
ull q[L],s[N][2],t[2][N];
ull fnd(int x,int y,int z){
	return t[z][y]-t[z][x-1]*q[y-x+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	q[0]=1ull;
	for(int i=1;i<=5e6;i++) q[i]=q[i-1]*p;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		s[i][0]=s[i][1]=0ull;
		scanf("%s",S+1);
		ch=S[1]-'a'+1;
		nxt[i]=lst[ch],lst[ch]=i;
		ln[i]=strlen(S+1);
		for(int j=1;j<=ln[i];j++) s[i][0]=s[i][0]*p+(S[j]-'a'+1);
		scanf("%s",S+1);
		for(int j=1;j<=ln[i];j++) s[i][1]=s[i][1]*p+(S[j]-'a'+1);
	}
	while(k--){
		ans=0;
		l=r=m=Mx=0,t[0][0]=t[1][0]=0ull;
		for(int i=1;i<=26;i++) cnt[i]=0;
		scanf("%s",T[0]+1);
		m=strlen(T[0]+1);
		scanf("%s",T[1]+1);
		for(int j=1;j<=m;j++){
			ch=T[0][j]-'a'+1;
			cnt[ch]++,Mx=max(Mx,cnt[ch]);
			t[0][j]=t[0][j-1]*p+(T[0][j]-'a'+1);
			t[1][j]=t[1][j-1]*p+(T[1][j]-'a'+1);
			if(T[0][j]!=T[1][j]){
				if(l==0) l=j;
				r=j;
			}
		}
		if(Mx<m/2){
			for(int i=1;i<=l;i++){
				for(int j=lst[T[0][i]-'a'+1];j>0;j=nxt[j]){
					if(i+ln[j]-1<r||i+ln[j]-1>m) continue;
					if(fnd(i,i+ln[j]-1,0)==s[j][0]){
						if(fnd(i,i+ln[j]-1,1)==s[j][1]) ans++;
					}
				}
			}
		}
		else{
			for(int i=1;i<=l;i++){
				for(int j=1;j<=n;j++){
					if(i+ln[j]-1<r||i+ln[j]-1>m) continue;
					if(fnd(i,i+ln[j]-1,0)==s[j][0]){
						if(fnd(i,i+ln[j]-1,1)==s[j][1]) ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
