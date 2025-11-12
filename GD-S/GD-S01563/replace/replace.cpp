#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define N 200005
#define M 15000005
#define ll long long
using namespace std;
const int INF=1e9;
char s1[M/3],s2[M/3];
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int x=0;
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
int reads1(){
	int len=0;
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while('a'<=c&&c<='z') s1[len++]=c,c=getchar();
	return len;
}
int reads2(){
	int len=0;
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while('a'<=c&&c<='z') s2[len++]=c,c=getchar();
	return len;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,Q;
int a[M],lena,lens1,lens2;
queue<int>q;
struct Tire_tree{
	int tr[M][27],fail[M],tot;
	ll cnt[M];
	void insert(int l,int r){
		int pos=0;
		for(int i=l;i<=r;i++)
			pos=(tr[pos][a[i]]?tr[pos][a[i]]:tr[pos][a[i]]=++tot);
		cnt[pos]++;
	}
	void build(){
		for(int i=0;i<27;i++) if(tr[0][i]) q.push(tr[0][i]);
		int u;
		while(!q.empty()){
			u=q.front(); q.pop(); 
			cnt[u]+=cnt[fail[u]];
			for(int i=0;i<27;i++){
				if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
				else tr[u][i]=tr[fail[u]][i];
			}
		}
	}
	ll query(int l,int r){
		if(l>r) return 0;
		int pos=0;
		ll res=0;
		for(int i=l;i<=r;i++){
			pos=tr[pos][a[i]];
			res+=cnt[pos];
		}
		return res;
	}
}tr;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),Q=read();
	for(int i=1;i<=n;i++){
//		scanf("%s%s",s1,s2);
//		lens=strlen(s1);
		lens1=reads1(),lens2=reads2();
		lena=0;
		for(int j=0;j<lens1;j++) a[++lena]=s1[j]-'a',a[++lena]=s2[j]-'a',a[++lena]=26;
		tr.insert(1,lena);
	} 
	tr.build();
	int l,r;
	for(int i=1;i<=Q;i++){
//		scanf("%s%s",s1,s2);
//		lens=strlen(s1);
		lens1=reads1(),lens2=reads2();
		if(lens1!=lens2){
			putchar('0'),putchar('\n');
			continue;
		}
		lena=0;
		for(int j=0;j<lens1;j++) a[++lena]=s1[j]-'a',a[++lena]=s2[j]-'a',a[++lena]=26;
		l=-INF,r=INF;
		for(int j=1;j<=lena;j+=3) if(a[j]!=a[j+1]){l=j;break;}
		for(int j=lena;j>=1;j-=3) if(a[j-2]!=a[j-1]){r=j;break;}
		write(tr.query(1,lena)-tr.query(l+3,lena)-tr.query(1,r-3)+tr.query(l+3,r-3));
		putchar('\n');
	}
	return 0;
}
