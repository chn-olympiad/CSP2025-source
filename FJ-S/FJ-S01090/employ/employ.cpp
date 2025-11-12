#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500+7;
const int mod=998244353;
int in(){
	int x=0;
	int f=1;
	char c;
	c=getchar();
	while(c!='-'&&(!(c>='0'&&c<='9'))) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
	return x;
}
int b[N],v[N],ans;
int n,m,A=1;
char s[N];
int c[N];
void dfs(int x){
	if(x>n){
		int q=0;
		for(int i=1;i<=n;i++){
			if(q>=c[b[i]]){
				q++;
			}else{
				if(s[i]=='0') q++;
			}
		}
		if(n-q>=m) ans++;
		
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			b[x]=i;
			dfs(x+1);
			v[i]=0;
			b[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in();m=in();
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') A=0;
	}
	for(int i=1;i<=n;i++) c[i]=in();
	dfs(1);
	printf("%d\n",ans);
	return 0;
}