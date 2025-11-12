#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define N 505
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(-x);return;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int n,m,used[N],p[N],k[N],sum;
char c[N];
void dfs(int now){
	if(now==n+1){
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt>=k[p[i]])cnt++;
			else if(c[i]=='0')cnt++;
			else ans++;
		}
		if(ans>=m)sum++;
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		p[now]=i;
		used[i]=1;
		dfs(now+1);
		used[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	dfs(1);
	cout<<sum;
	return 0;
}
//Rp++ 

