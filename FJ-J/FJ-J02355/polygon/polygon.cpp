#include<stdio.h>
#include<algorithm>
int n,a[5005];
long long c[5005][5005],mod=998244353;
int max_(int a,int b){return a>b?a:b;}
void init(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i)c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}
long long ans=0;
void dfs(int maxl,int inx,int b[],int op[],long long sum,int pev){
	if(inx>maxl){
		if(sum>2*b[0])ans=(ans+1)%mod;
		return;
	}
	for(int i=pev+1;i<=n-maxl+inx;i++){
		if(!op[i]){
			op[i]=1;
			b[inx]=a[i];
			sum+=a[i];
			if(a[i]>b[0])b[0]=a[i];
			dfs(maxl,inx+1,b,op,sum,i);
			op[i]=0;
			sum-=a[i];
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1)cnt++;
	}
	std::sort(a+1,a+1+n);
	if(n==3){
		if((a[1]+a[2]+a[3])>2*max_(max_(a[1],a[2]),a[3])){
			printf("1");
		}else{
			printf("0");
		}
	}else if(cnt==n){
		init(cnt);
		for(int i=3;i<=cnt;i++){
			ans=(ans%mod+c[cnt][i]%mod)%mod;
		}
		printf("%lld",ans%mod);
	}else{
		for(int i=3;i<=n;i++){
			int b[5005]={0},op[5005]={0};
			dfs(i,1,b,op,0,0);
		}
		printf("%lld",ans%mod);
	}
	return 0;
}