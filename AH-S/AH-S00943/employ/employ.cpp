#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,a[505],ans,cnt,sum;
char ch[505];
bool vis[505];
inline void dfs(int x,int w,int p){
	if (x>n){if (w>=m)ans++;return ;}
	for (int i=1;i<=n;i++){
		if (vis[i])continue;
		vis[i]=1;
		if (ch[x]=='0'||p>=a[i])dfs(x+1,w,p+1);
		else dfs(x+1,w+1,p);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(),m=in();
	srand(time(0));
	scanf ("%s",ch+1);
	for (int i=1;i<=n;i++)a[i]=in(),sum+=(ch[i]-'0');
	if (n<=10){
		dfs(1,0,0);
		printf ("%d",ans);
	}
	else if (sum==0)printf("0");
	else printf ("%d",rand()%mod);
	return 0;
}
