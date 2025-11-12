#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+5,p=231,mod=998244353;
int n,m,q,l,r,len[N],nxt[N],v[N],now,ans,L,R;
ll a,b,s[N],t[N],w[N],ta[N],tb[N];
string A,B;
map<pair<int,int>,int>fir;
ll S(int x,int y){return (s[y]-s[x-1]*w[y-x+1]%mod+mod)%mod;}
ll T(int x,int y){return (t[y]-t[x-1]*w[y-x+1]%mod+mod)%mod;}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	w[0]=1;for(int i=1;i<N;i++) w[i]=w[i-1]*p%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>A>>B;len[i]=m=A.length();
		r=-1;a=b=0;
		for(int j=0;j<m;j++) if(A[j]!=B[j]){l=j;break;}
		for(int j=m-1;j>=0;j--) if(A[j]!=B[j]){r=j;break;}
		if(r==-1) continue;
		for(int j=l;j<=r;j++) a=(a*p+A[j]-'a'+1)%mod,b=(b*p+B[j]-'a'+1)%mod;
		for(int j=0;j<m;j++) ta[i]=(ta[i]*p+A[j]-'a'+1)%mod;
		for(int j=0;j<m;j++) tb[i]=(tb[i]*p+B[j]-'a'+1)%mod;
		v[i]=l;nxt[i]=fir[{a,b}];fir[{a,b}]=i;
	}for(int i=1;i<=q;i++){
		cin>>A>>B;
		if((m=A.length())!=B.length()){printf("0\n");continue;}
		a=b=ans=0;
		for(int j=0;j<m;j++) if(A[j]!=B[j]){l=j;break;}
		for(int j=m-1;j>=0;j--) if(A[j]!=B[j]){r=j;break;}
		for(int j=l;j<=r;j++) a=(a*p+A[j]-'a'+1)%mod,b=(b*p+B[j]-'a'+1)%mod;
		for(int j=0;j<m;j++) s[j]=(s[max(0,j-1)]*p+A[j]-'a'+1)%mod;
		for(int j=0;j<m;j++) t[j]=(t[max(0,j-1)]*p+B[j]-'a'+1)%mod;
		now=fir[{a,b}];
		while(now){
			L=l-v[now];R=L+len[now]-1;
			if(L>=0&&R<m) ans+=(ta[now]==S(L,R)&&tb[now]==T(L,R));
			now=nxt[now];
		}printf("%d\n",ans);
	}fclose(stdin);fclose(stdout); 
return 0;}
