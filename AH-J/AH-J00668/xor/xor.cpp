#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,k,a[N],cnt,sum[N],pre;
bool A=1,B=1,vis[N];
void dfs(LL pre,LL t){
	cnt=max(cnt,t);
	for(LL i=pre+1;i<=n;i++){
		if(!vis[i]){
			for(LL j=i;j<=n;j++){
				if(LL(sum[j]^sum[i-1])==k){
					for(LL k=i;k<=j;k++)	vis[k]=1;
					dfs(i,t+1);
					for(LL k=i;k<=j;k++)	vis[k]=0;
				}
			}
			
		}
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)	A=0;
		if(a[i]!=0&&a[i]!=1)	B=0;
		sum[i]=sum[i-1]^a[i];
	}
	if(A){
		if(k==0){
			if(n==1)	puts("0");
			else if(n==2) puts("1");
			else printf("%lld",n/2);
		} 
	}
	else if(n<=10){
		dfs(0,0);
		printf("%lld",cnt);
	}
	else{
		if(k==0){
			for(LL i=1;i<=n;i++){
				for(LL j=i+1;j<=n;j++){
					if(a[i]==a[j]){
						cnt++;
						break;
					}
				}
			}
		}
		else{
			for(LL l=1;l<=n;l++){
				for(LL r=l;r<=n;r++){
					//cout<<l<<' '<<r<<endl;
					if(LL(sum[r]^sum[l-1])==k){
						pre=r;
						//cout<<pre<<endl;
						cnt++;
						break;
					}
				}
				if(pre>l)	l=pre;
			}
		}
		printf("%lld",cnt);
	}
	return 0;
}
