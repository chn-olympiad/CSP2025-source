#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e4,mod=998244353;
int n,a[N],sum[N],sum2[N],ans;
bool book[N];
void dfs(int x,int k,int sum,int maxx){
	for(int i=x+1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			//cout<<i<<" "<<k<<" "<<sum<<" "<<maxx<<endl; 
			if(k>=3 && sum+a[i]>max(maxx,a[i])*2) ans=(ans+1)%mod;
			dfs(i,k+1,sum+a[i],max(maxx,a[i]));
			book[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	dfs(0,1,0,0);
	printf("%d",ans);
	return 0;
}

