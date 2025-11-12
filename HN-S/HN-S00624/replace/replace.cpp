/* ChongYun */
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void read(string &str){
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	while(ch>='a'&&ch<='z') str+=ch,ch=getchar();
}
const int N=5e6+5;
int n,m,len[N],Len[N];
string s[N][2],t[N][2];
ull base=131,Hash[2],HashT[2][N],pw[N];
ull query(int op,int l,int r){ return HashT[op][r]-HashT[op][l-1]*pw[r-l+1]; }
map<pair<ull,ull>,int> vis;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		read(s[i][0]),read(s[i][1]);
		len[i]=s[i][0].size();
		s[i][0]=' '+s[i][0],s[i][1]=' '+s[i][1];
		Hash[0]=Hash[1]=0;
		for(int j=1;j<=len[i];++j) Hash[0]=Hash[0]*base+s[i][0][j];
		for(int j=1;j<=len[i];++j) Hash[1]=Hash[1]*base+s[i][1][j];
		++vis[{Hash[0],Hash[1]}];
	}
	int sp=0;
	for(int i=1;i<=m;++i){
		read(t[i][0]),read(t[i][1]);
		Len[i]=t[i][0].size();
		t[i][0]=' '+t[i][0],t[i][1]=' '+t[i][1];
		sp+=Len[i];
	}
	pw[0]=1;
	for(int i=1;i<=5e6;++i) pw[i]=pw[i-1]*base;
	if(sp<=2000){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=Len[i];++j) HashT[0][j]=HashT[0][j-1]*base+t[i][0][j];
			for(int j=1;j<=Len[i];++j) HashT[1][j]=HashT[1][j-1]*base+t[i][1][j];
			int res=0;
			for(int l=1;l<=Len[i];++l){
				for(int r=l;r<=Len[i];++r){
					if(query(0,1,l-1)==query(1,1,l-1)&&query(0,r+1,Len[i])==query(1,r+1,Len[i])) res+=vis[{query(0,l,r),query(1,l,r)}];
				}
			}
			printf("%lld\n",res);
		}
		return 0;
	}
	if(m==1){
		int p0=0,p1=0;
		for(int j=1;j<=Len[1];++j) if(t[1][0][j]=='b') p0=j;
		for(int j=1;j<=Len[1];++j) if(t[1][1][j]=='b') p1=j;
		int res=0;
		for(int i=1;i<=n;++i){
			int P0=0,P1=0;
			for(int j=1;j<=len[i];++j) if(s[i][0][j]=='b') P0=j;
			for(int j=1;j<=len[i];++j) if(s[i][1][j]=='b') P1=j;
			if(P0<=p0&&len[i]-P1+1<=Len[1]-p1+1&&p1-p0==P1-P0) ++res;
		}
		printf("%lld\n",res);
		return 0;
	}
	return 0;
}
