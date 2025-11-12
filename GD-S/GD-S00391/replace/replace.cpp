#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int ha[200005][2],len;
const int base=131;
int dp[5000005],pw[5000005];
int s1[5000005],s2[5000005];
int Len[200005];
int hash1(int i,int j){
	return s1[j]-s1[i-1]*pw[j-i+1];
}
int hash2(int i,int j){
	return s2[j]-s2[i-1]*pw[j-i+1];
}
int ans=0;
void dfs(int T,int s,int t){
	if(s==t){
		ans++;
		return ;
	}
	if(T>n){
		return ;
	}
	dfs(T+1,s,t);
	for(int i=Len[T];i<=len;i++){
		int f1=hash1(i-Len[T]+1,i);
		int f2=hash2(i-Len[T]+1,i);
		if(f1==ha[T][0]&&f2==ha[T][1]){
			int t1=hash1(1,i-Len[T]);
			int t2=hash1(i+1,len);
			dfs(T+1,t1*pw[Len[T]+len-i]+f2*pw[len-i]+t2,t);
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*base;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		char c=getchar();
		while(c>'z'||c<'a') c=getchar();
		while(c>='a'&&c<='z'){
			Len[i]++;
			ha[i][0]=ha[i][0]*base+c-'a'+1;
			c=getchar();
		}
		while(c>'z'||c<'a') c=getchar();
		while(c>='a'&&c<='z'){
			ha[i][1]=ha[i][1]*base+c-'a'+1;
			c=getchar();
		}
	}
	while(q--){
		len=0;
		char c;
		while(c>'z'||c<'a') c=getchar();
		while(c>='a'&&c<='z'){
			++len;
			s1[len]=s1[len-1]*base+c-'a'+1;
			c=getchar();
		}
		len=0;
		while(c>'z'||c<'a') c=getchar();
		while(c>='a'&&c<='z'){
			++len;
			s2[len]=s2[len-1]*base+c-'a'+1;
			c=getchar();
		}
		ans=0;
		dfs(1,s1[len],s2[len]);
		printf("%lld\n",ans);
	}
	return 0;
}
