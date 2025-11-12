#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans=0;
char a[100005];
long long b[100005];
long long s[100005];
bool jl[100005];
long long sum=0,js=1;
bool flag=true;
long long k;
inline long long read(){
	char x=getchar();
	k=0;
	while(!('0'<=x&&x<='9'))x=getchar();
	while('0'<=x&&x<='9'){
		k*=10;
		k+=x-'0';
		x=getchar();
	}
	return k;
}
void check(){
	long long x=0;
	for(int i=1;i<=n;i++){
		if(x>=b[s[i]]||a[i-1]=='0')x++;
	}
	if(n-x>=m)ans++;
	ans%=mod;
	return;
}void dfs(int x){
	if(x==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!jl[i]){
			jl[i]=true;
			s[x]=i;
			dfs(x+1);
			jl[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='0'){
			flag=false;
			break;
		}
	}for(int i=1;i<=n;i++){
		b[i]=read();
		if(b[i]==0)sum++;
	}
	if(flag){//ÌØÊâÐÔÖÊA 
		if(n-sum>=m){
			for(int i=n;i>=1;i--){
				js*=i;
				js%=mod;
			}
			cout<<js;
		}
		else cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
