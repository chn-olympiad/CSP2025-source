#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=507,inf=(1<<31)-1,Mod=998244353;

char a[N],b[N];
int f[N];

int solve(int u){
	f[1]=1,f[2]=2;
	for(int i=3;i<=u;i++)
	f[i]=( (f[i-1]%Mod)*(i%Mod) )%Mod;
	return f[u];
}

int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]);
		scanf("%d",b[i]);
	}
	int ans=solve(n)%mod;
	printf("%d",ans);
	return 0;
}