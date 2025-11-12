#include<cstdio>
int n,k,a[500005],ans;
int f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		f[i]=f[i-1]^a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if (a[i]==0) ans++;
			else if(a[i]==a[i+1]) ++ans,++i;
		}
		printf("%d",ans);
	}else if(k==1){
		for(int i=1;i<=n;++i){
			if(a[i]==1) ans++;
			else if(a[i]!=a[i+1]) ++ans,++i;
		}
		printf("%d",ans);
	}
		else{
			for(int sum=0,i=1;i<=n;++i){
					for(int j=i;j>sum;--j){
						if((f[i]^f[j-1])==k) {
							sum=i;++ans;break;
						}
				}
			}
			printf("%d",ans);
	}
	return 0;
}