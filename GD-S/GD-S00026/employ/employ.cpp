#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
typedef long long ll;
const ll mod=998244353;
int c[maxn],b[maxn],suf[maxn];
bool vis[maxn];
int n,m,sum;
string s;
void dfs(int x,int y){
	if(y+suf[x-1]<m) return;
	if(x==n+1){
		if(y>=m) ++sum;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			if(x-y-1>=c[i]||s[x-1]=='0') b[x]=-b[x],dfs(x+1,y);
			else dfs(x+1,y+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		char c=getchar();
		while(c!='0'&&c!='1') c=getchar();
		s+=c;
	}
	for(int i=n-1;i>=0;--i) suf[i]=suf[i+1]+(s[i]=='1');
	for(int i=1;i<=n;++i) scanf("%d",c+i);
	dfs(1,0);
	printf("%d",sum);
}
/*
zmx lsy
千万不要删这行，别问我为什么，删了会寄
*/
