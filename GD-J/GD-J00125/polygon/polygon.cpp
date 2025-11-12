#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=5005;
const int mod=998244353;

long long sum;
int n;
int a[N];
bool flag;

void dfs(int id,int cnt,int sumans,int maxans){
	if(id==n+1){
		if(cnt>=3&&sumans>maxans*2){
			sum=(sum+1)%mod;
		}
		return;
	}
	dfs(id+1,cnt,sumans,maxans);
	dfs(id+1,cnt+1,sumans+a[id],max(maxans,a[id]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)flag=true;
	}
	if(flag==false){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%mod;
		}
		ans-=(1+n*(n-1)/2+n);
		printf("%lld",ans);
	}else{
		sort(a+1,a+n+1);
		dfs(1,0,0,-0x3f3f3f3f);
		printf("%lld",sum);
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
