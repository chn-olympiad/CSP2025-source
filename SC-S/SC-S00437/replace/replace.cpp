#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=5e6+5;
int n,q;
string s[N][2];
int f[N];
int len[N];
//void getnxt(int x,string si){
//	nxt[x][1]=0;
//	int j=0;
//	for(int i=1;i<len[x];++i){
//		while(j>0&&si[i]!=si[j+1])  j=nxt[x][j];
//		if(si[i]==si[j+1])  ++j;
//		nxt[x][i]=j;
//	}
//}
void getf(int x,int l){
	for(int i=0;i<l;++i)
	  if(s[x][0][i]!=s[x][1][i]){
	  	f[x]=i;break;
	  }
}
bool check(int x,char t1[],char t2[],int l){
	int j=0;
	for(int i=0;i<l;++i)
	  if(t1[i]!=t2[i]){
	  	j=i;break;
	  }
	if(j<f[x])  return 0;
	for(int i=j-f[x];i<=j-f[x]+len[x];++i){
		if(s[x][0][i-(j-f[x])]!=t1[i])  return 0;
		if(s[x][1][i-(j-f[x])]!=t2[i])  return 0;
	}
	for(int i=j-f[x]+len[x]+1;i<l;++i)
	  if(t1[i]!=t2[i])
	    return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0];
		cin>>s[i][1];
		len[i]=s[i][0].size();
		getf(i,len[i]);
//		getnxt(i,s[i][0]);
	}
	while(q--){
		int ans=0;
		char t1[M],t2[M];
		cin>>t1;
		cin>>t2;
		int siz1=strlen(t1),siz2=strlen(t2);
		if(siz1!=siz2){
			printf("0\n");
			continue;
		}
		int siz=siz1,sum=0;
		for(int i=0;i<siz;++i)
		  if(t1[i]!=t2[i])
		    sum++;
		for(int i=1;i<=n;++i){
			if(sum>len[i])  continue;
			if(check(i,t1,t2,siz))  ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
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