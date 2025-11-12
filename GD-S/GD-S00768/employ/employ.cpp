#include<bits/stdc++.h>
using namespace std;

const int MaxN=510;
const long long mod=998244353;

int n,m;
long long ans;
int s[MaxN];
int c[MaxN];
int a[MaxN];
bool b[MaxN];

int check(){
	int sum=0,tot=0;
	for(int i=1;i<=n;i++){
		int j=a[i];
		if(sum>=c[j]){
			sum++;
			continue;
		}
		if(s[i])tot++;
		else sum++;
	}
	return tot;
} 

void dfs(int x){
	if(x==n+1){
		if(check()>=m)(ans+=1)%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		b[i]=1;
		a[x]=i;
		dfs(x+1);
		b[i]=0;
	} 
}
bool f(){
	for(int i=1;i<=n;i++)if(s[i]==0)return false;
	return true;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	
	if(f()){
		ans=1;
		for(int i=1;i<=n;i++)(ans*=i)%=mod;
	}
	else dfs(1);
	
	printf("%lld",ans%mod);
	
	return 0;
} 
