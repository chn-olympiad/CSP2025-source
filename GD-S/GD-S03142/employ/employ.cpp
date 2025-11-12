#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc() getchar()
#define putc(c) putchar(c)
inline int read(){
	int x=0,t=0;
	char c=gc();
	while(c<'0'||c>'9') t|=c=='-',c=gc();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
	return t?-x:x;
}
inline void write(int x){
	if(x<0) putc('-'),x=-x;
	if(x>9) write(x/10);
	putc(x%10+'0');
}
inline char getc(){
	char c=gc();
	while(c<'0'||c>'1') c=gc();
	return c;
}
#define mpr make_pair
#define pii pair<int,int>
#define fir first
#define sec second
const int N=500+10,mod=998244353;
inline int add(int x,int y){ return x+y>=mod?x+y-mod:x+y; }
inline int dec(int x,int y){ return x>=y?x-y:x+mod-y; }
inline void inc(int &x,int y){ x=add(x,y); }
int n,m,s[N],c[N],f[2][N][N],fac[N],nx[N];
/*
直接考虑判定合法数量
判定方法：记录前面的不合法数量即可
为了 DP，我们额外记录前面不合法的最小 c，只有比它还小的才考虑 
设 f[i][j][k] 表示考虑到 i，要求前面有 j 个合法，后面有 k 个要求在上面的 
*/
inline void Prefix(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
}
int main(){
//	system("fc employ1.out employ1.ans /n");
//	system("fc employ2.out employ2.ans /n");
//	system("fc employ3.out employ3.ans /n");
//	system("fc employ4.out employ4.ans /n");
//	system("fc employ5.out employ5.ans /n");
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	Prefix(n);
	vector<int>pos;
	for(int i=1;i<=n;i++)
		if(getc()=='1')
			pos.push_back(i);
	for(int i=1;i<=n;i++)
		c[i]=read();
	sort(c+1,c+n+1);
	c[0]=-1,c[n+1]=n+1;
	for(int i=1;i<=n+1;i++)
		for(int j=c[i-1]+1;j<=c[i];j++)
			nx[j]=i;
//	for(auto p:pos) printf("%d ",p);puts("");
//	for(int i=1;i<=n;i++) printf("%d ",c[i]);puts(""); 
	int t=0;
	for(int i=m;i<=n;i++) 
		f[0][i][0]=1;
	reverse(pos.begin(),pos.end());
	int cl=pos.size(),cr=0;
	for(int i:pos){
		for(int j=0;j<=cl;j++)
			for(int k=0;k<=cr;k++){
				int w=f[t][j][k];
				if(!w) continue;
				f[t][j][k]=0;
//				printf("f[%d][%d][%d]=%d\n",i,j,k,w);
				//i 合法，要求 c_i>=i-(j-1) 
				if(j) inc(f[!t][j-1][k+1],1ll*w*(n-nx[i-j+1]+1-k)%mod);
				//i 不合法，要求 c_i<i-j，容斥
				inc(f[!t][j][k],w);
				inc(f[!t][j][k+1],1ll*dec(0,w)*(n-nx[i-j]+1-k)%mod); 
			}
		cl--,cr++,t^=1;
	}
	int s=0;
	for(int k=0;k<=n;k++)
		inc(s,1ll*f[t][0][k]*fac[n-k]%mod);
	write(s);
}
/*
3 1
111
0 1 1
*/
