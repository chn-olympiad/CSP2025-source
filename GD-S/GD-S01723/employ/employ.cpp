#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=5e2+10;
int n,m,c[N];
bool vis[N];
int b[N];
int ans;
string str;
void dfs(int depth){
	if(depth==n+1){
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			if(cnt<c[b[i]])
				tot++;
			if(str[i]=='0')
				cnt++;
		}
		if(tot>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			b[depth]=i;
			dfs(depth+1);
			b[depth]=0;
			vis[i]=0;
		}
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>str;str=" "+str;
	for(int i=1;i<=n;i++)
		c[i]=read();
	dfs(1);
	printf("%lld\n",ans);
    return 0;
}
