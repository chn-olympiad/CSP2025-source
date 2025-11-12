#include<cstdio>
int n,a[5005];
bool s[5005];
const int mod=998244353;
int max(int a,int b){
	return (a>b?a:b);
}
int ans;
void dfs(int k){
	if(k>n){
		int cnt=0,sum=0,maxn=-100;
		for(int i=1;i<=n;i++){
			if(s[i]){
				cnt++;
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		if(cnt>=3&&sum>maxn*2){
			ans++;
		}
		return;
	}
	s[k]=1;
	dfs(k+1);
	s[k]=0;
	dfs(k+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3){
		printf("0");
		return 0;
	} 
	if(n==3){
		int maxn=-1000,sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>maxn*2)printf("1");
		else printf("0");
		return 0;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
