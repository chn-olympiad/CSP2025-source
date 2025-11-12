#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N];
long long ans,maxi,mul[N];
vector<int> e;
void dfs(int tmp,int d,int s,int mx){
	if(tmp==d+1){
//		for(int i=0;i<d;i++)printf("%d ",e[i]);
		if(s>2*a[mx-1]){
			ans=(ans+1)%mod;
//			puts("Accept");
		}else{
//			puts("Refuse");
		}
		return;
	}
	for(int i=mx;i<=n;i++){
		e.push_back(i);
//		printf("case:%d;i:%d\n",tmp,i);
		dfs(tmp+1,d,s+a[i],i+1);
		e.pop_back();
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	mul[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxi=(a[i]>maxi?a[i]:maxi);
		mul[i]=(unsigned long long)(mul[i-1]*i);
	}
	sort(a+1,a+1+n);
	if(maxi==1){
		for(int i=3;i<=n;i++){
			ans=(ans+(mul[n]/(mul[i]*mul[n-i])))%mod;
		}
		printf("%lld",ans);
	}else{
		for(int i=3;i<=n;i++){
//			puts("---------next---------");
			dfs(1,i,0,1);
		}
		printf("%lld",ans);
	}
	return 0;
}
