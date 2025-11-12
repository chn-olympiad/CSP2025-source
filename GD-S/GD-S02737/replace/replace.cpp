#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=2e5+3,M=5e6+3;
const ull bas=13331;
char S[M],T[M];
ull s[N],t[N],x[N],y[N],pw[M];
ull calcx(int l,int r){return x[r]-x[l-1]*pw[r-l+1];}
ull calcy(int l,int r){return y[r]-y[l-1]*pw[r-l+1];}
int n,q,ln[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	pw[0]=1;for(int j=1;j<=5000000;j++) pw[j]=pw[j-1]*bas;
	for(int i=1,len;i<=n;i++){
		scanf("%s%s",S+1,T+1),ln[i]=len=strlen(S+1);
		for(int j=1;j<=len;j++) s[i]=s[i]*bas+S[j],t[i]=t[i]*bas+T[j];
	}
	if(n<=1000){
		while(q--){
			scanf("%s%s",S+1,T+1);
			if(strlen(S+1)!=strlen(T+1)){puts("0");continue;}
			int L,R,len=strlen(S+1),ans=0;
			for(int j=1;j<=len;j++) if(S[j]!=T[j]){L=j;break;}
			for(int j=len;j>=1;j--) if(S[j]!=T[j]){R=j;break;}
			for(int j=1;j<=len;j++) x[j]=x[j-1]*bas+S[j],y[j]=y[j-1]*bas+T[j];
			for(int j=1;j<=L;j++) for(int i=1;i<=n;i++){
				int l=j,r=j+ln[i]-1;
				if(r>=R && r<=len && calcx(l,r)==s[i] && calcy(l,r)==t[i]) ans++;
			}
			printf("%d\n",ans);
		}
	}else{
		while(q--) puts("0");
	}
	return 0;
}
/*
2 1
abcabcabc abdabdabd
dabcabcabcd dabdabdabdd
aadabcabcabcdaa aadabdabdabddaa

*/
