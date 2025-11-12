#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SZ=500+3;
const int MOD=998244353;

int n,m,c[SZ],ans;
bool book[SZ],flag=1;
char s[SZ];

ll read(){
	ll res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c-'0');
		c=getchar();
	}
	return res*f;
}
void dfs(int num,int no){
	//printf("num==%d,no=%d\n",num,no);
	if(num==n){
		if(no<=n-m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		book[i]=1;
		if(no>=c[i]||s[num+1]=='0') dfs(num+1,no+1);
		else dfs(num+1,no);
		book[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=18){
		dfs(0,0);
		printf("%d",ans);
	}
	else{
		for(int i=1;i<=m;i++) if(s[i]=='0') flag=0;
		if(flag){
			int num=0;
			for(int i=1;i<=n;i++)if(c[i]>0) num++;
			if(num>=m){
				ans=1;
				for(int i=1;i<=n;i++) ans=1LL*ans*i%MOD;
			}
			else ans=0;
			printf("%d",ans);
		}
		else{
			dfs(0,0);
			printf("%d",ans);
		}
	}
	return 0;
}

