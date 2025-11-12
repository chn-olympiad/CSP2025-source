#include<stdio.h>
long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0,cnt1=0;
	char s[505]={0};
	int c[505]={0};
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(int i=0;s[i]!=0;i++)cnt1+=s[i]-'0';
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0){
			cnt++;
			c[i]=-1;
		}
	}
	if(cnt1<m){
		printf("0");
		return 0;
	}
	while(1){
		int f=1;
		for(int i=1;i<=n;i++){
			if(cnt>=c[i]&&c[i]>=0){
//			printf("%d %d\n",cnt,c[i]);
				f=0;
				cnt++;
				c[i]=-1;
			}
		}
		if(f)break;
	}
//	printf("%d\n",cnt);
	if(n-cnt<m){
		printf("0");
		return 0;
	}
//	printf("%d %d %d\n",n,cnt,m);
	long long ans=1;
	for(int i=2;i<=n-cnt;i++){
		ans=((ans%mod)*(i%mod))%mod;
//		printf("%d %lld\n",i,ans);
	}
	printf("%lld",ans%mod);
	return 0;
}