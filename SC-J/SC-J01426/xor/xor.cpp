#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,k,ans;
long long a[N],lt[N];
bool pa,pb,pc;

void dfs(long long st,long long cnt){
	ans=max(ans,cnt);
	if(st>n)return;
	long long ed=1e8;
	for(long long i=st;i<=n;i++){
		ed=min(ed,lt[i]);
	}
	if(ed!=1e8) dfs(ed+1,cnt+1);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	pa=pb=pc=1;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)pa=0;
		if(a[i]>1)pb=0;
		if(a[i]>255)pc=0;
	}
	ans=0;
	if(pa==1&&k==0){
		ans=(n-n%2)/2;
	}else{
		long long x;
		for(long long i=1;i<=n;i++){
			x=a[i];
			lt[i]=1e8;
			for(long long j=i+1;j<=n+1;j++){
				if(x==k){
					lt[i]=j-1;
					break;
				}
				x^=a[j];
			}
		}
		dfs(1,0);
	}
	printf("%lld",ans);
	return 0;
}