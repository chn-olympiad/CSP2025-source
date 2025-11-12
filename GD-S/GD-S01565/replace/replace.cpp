#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e6+5e5,U=M<<1;
char a[M],b[M],c[U];
int son[U][27],len,id;
int n,q,f[U],nx[U];
inline void insert(){
	int p=0;
	for(int i=0;i<=len;i++){
		if(!son[p][c[i]-'a']) son[p][c[i]-'a']=++id;
		p=son[p][c[i]-'a'];
	}f[p]++;
}
inline void getfail(){
	queue<int> Q;
	for(int i=0;i<=26;i++) if(son[0][i]) Q.push(son[0][i]);
	while(Q.size()){
		int p=Q.front();Q.pop();
		for(int i=0;i<=26;i++)
			if(son[p][i]) Q.push(son[p][i]),nx[son[p][i]]=son[nx[p]][i];
			else son[p][i]=son[nx[p]][i];
	}
}
int F[U];
inline int ask(int k){
	int p=0,ans=0;
	for(int i=k;i<=len;i++) p=son[p][c[i]-'a'],ans+=f[p];
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf(" %s %s",a,b);
		int l=-1,r=-1,la=strlen(a);
		for(int k=0;k<la;k++) if(a[k]!=b[k]){l=k;break;}
		for(int k=la-1;k>=0;k--) if(a[k]!=b[k]){r=k;break;}
		if(l!=-1){
			len=0;
			for(int k=0;k<=r;k++) c[len++]=a[k];c[len++]='z'+1;
			for(int k=l;k<=r;k++) c[len++]=b[k];c[len++]='z'+1;
			for(int k=r+1;k<la;k++) c[len++]=a[k];len--;
		}insert();
	}//getfail();
	int id=0;
	while(q--){
		scanf(" %s %s",a,b);
		int l=-1,r=-1,la=strlen(a);
		for(int k=0;k<la;k++) if(a[k]!=b[k]){l=k;break;}
		for(int k=la-1;k>=0;k--) if(a[k]!=b[k]){r=k;break;}
		int len=0;
		for(int k=0;k<=r;k++) c[len++]=a[k];c[len++]='z'+1;
		for(int k=l;k<=r;k++) c[len++]=b[k];c[len++]='z'+1;
		for(int k=r+1;k<la;k++) c[len++]=a[k];len--;
		int ans=0;
		for(int i=0;i<=la;i++) ans+=ask(i);
		printf("%d\n",ans);
	}
	return 0;
}
