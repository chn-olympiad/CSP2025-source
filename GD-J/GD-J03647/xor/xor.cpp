#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+7,M=2e6+7; 
int n,m;
int a[N],s[N],t[M],dp[N],dpm[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	memset(t,0x3f,sizeof(t));
	t[0]=0;
	for(int i=1;i<=n;i++){
		int j=t[s[i]^m];
		if(j<=n) dp[i]=dpm[j]+1;
		dpm[i]=max(dp[i],dpm[i-1]);
		t[s[i]]=i;
//		printf("%d %d\n",i,dpm[i]);
	}
	ans=dpm[n];
	printf("%d",ans);
	return 0;
}
/*
4 0 
2 1 0 3
*/
