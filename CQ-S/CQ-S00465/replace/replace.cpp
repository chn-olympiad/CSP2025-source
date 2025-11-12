#include<bits/stdc++.h>
const int QWQ=5e6+5;
const int QaQ=2e5+5;
using namespace std;
using LL=long long;
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
//int tr[QWQ][26],fil[QWQ],cc[QWQ];
int n,q,len[QWQ],tot;
char c[QWQ],t[QWQ];
//inline void ins(int u,int id){
//	int l=strlen(c+1),ll=0;
//	for (int i=1;i<=l;i++){
//		if (!tr[u][c[i]-'a']) tr[u][c[i]-'a']=++tot;
//		u=tr[u][c[i]-'a'],len[u]=++ll;
//	}
//	cc[u]++;
//}
//inline void bfs(int s){
//	queue<int> q;
//	for (int i=0;i<26;i++){
//		fil[tr[s][i]]=s;
//		if (tr[s][i]) q.push(tr[s][i]);
//	}
//	for (;!q.empty();){
//		int u=q.front(),fu=fil[u]; q.pop();
//		cerr<<u<<' '<<fil[u]<<'\n';
//		for (int i=0;i<26;i++){
//			int &v=tr[u][i];
//			if (!v){ v=tr[fu][i]; continue; }
//			fil[v]=tr[fu][i],q.push(v); 
//		}
//	}
//	cerr<<"---------\n";
//}
char a[QWQ],b[QWQ];
#define ull unsigned long long
const ull pwr=127;
ull Ha[QWQ],Hb[QWQ],Hs[QWQ],Ht[QWQ];
ull pw[QWQ]; int La[QWQ],Lb[QWQ];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read(),tot=1;
//	if (n<=1000){
		for (int i=1;i<=n;i++){
			scanf("%s%s",a+1,b+1);
			ull HH=0; int la=strlen(a+1);
			for (int j=1;j<=la;j++) HH=HH*pwr+a[j];
			Ha[i]=HH,HH=0; int lb=strlen(b+1);
			for (int j=1;j<=lb;j++) HH=HH*pwr+b[j];
			Hb[i]=HH;
			La[i]=la,Lb[i]=lb;
		}
		pw[0]=1;
		for (int i=1;i<=2000;i++) pw[i]=pw[i-1]*pwr;
		for (;q--;){
			scanf("%s%s",a+1,b+1);
			int la=strlen(a+1),lb=strlen(b+1);
			if (la!=lb){ puts("0"); continue; }
			for (int i=1;i<=la;i++) Hs[i]=Hs[i-1]*pwr+a[i];
			for (int i=1;i<=lb;i++) Ht[i]=Ht[i-1]*pwr+b[i];
			int L=0,R=0;
			for (int i=1;i<=la;i++)
				if (a[i]!=b[i]){
					R=i; if (!L) L=i;
				}
			int ans=0;
			for (int i=1;i<=la;i++)
			for (int j=1;j<=n;j++){
				if (i+La[j]-1>la) continue;
				if (La[j]<R-L+1) continue;
				ull H1=Hs[i+La[j]-1]-Hs[i-1]*pw[La[j]];
				ull H2=Ht[i+La[j]-1]-Ht[i-1]*pw[La[j]];
				if (H1==Ha[j]&&H2==Hb[j]&&i<=L&&R<=i+La[j]-1){
					ans++;
				}
			}
			printf("%d\n",ans);
		}
//		return 0;
//	}
//	for (int i=1;i<=n;i++){
//		scanf("%s",c+1),ins(0,i);
//		scanf("%s",c+1),ins(1,i);
//	}
//	bfs(0);
//	bfs(1);
//	for (;q--;){
//		scanf("%s%s",c+1,t+1);
//		int lc=strlen(c+1),lb=strlen(t+1),L=0,R=0;
//		if (lc!=lb){ puts("0"); continue; }
//		for (int i=1;i<=lc;i++)
//			if (c[i]!=t[i]){
//				R=i; if (!L) L=i;
//			}
//		LL ans=0;
//		for (int i=1,x=0,y=1;i<=lc;i++){
//			for (;x&&!tr[x][c[i]-'a'];x=fil[x]);
//			for (;y!=1&&!tr[y][t[i]-'a'];y=fil[y]);
//			x=tr[x][c[i]-'a'],y=tr[y][t[i]-'a'];
//			cerr<<x<<' '<<y<<'\n';
//			if (cc[x]&&cc[y]&&len[x]==len[y]) ans+=cc[x];
////			if (i>=R&&cc[x]&&cc[y]&&len[x]==len[y]&&len[x]>=R-L+1) ans+=cc[x];
//		}
//		printf("%d\n",ans);
//	}
	return 0;
} 
