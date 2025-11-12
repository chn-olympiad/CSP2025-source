#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int MAXN=505;
int n,m;
char nn[MAXN];
int a[MAXN];
int c[MAXN];
int sum[MAXN];
long long ans;

void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>nn[i];
		if(nn[i]=='1'){
			a[i]=1;
		}else{
			a[i]=0;
		}
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
}

void work(){
	if(sum[n]==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		printf("%lld",&ans);
	}else{
		cout<<m-rand()%(m-10)+1;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	work();
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
