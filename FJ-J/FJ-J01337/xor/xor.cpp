#include<cstdio>
int n,k,a[500005];
bool f1=1,f01=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)f1=0;
		if(a[i]!=1&&a[i]!=0)f01=0;
	}
	if(f1){
		if(k==0){
			printf("%d",n/2);
		}else if(k==1){
			printf("%d",n);
		}else{
			printf("0");
		}
		return 0;
	}
	if(f01){
		if(k==1){
			int cnt1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt1++;
				}
			}
			printf("%d",cnt1);
		}else if(k==0){
			int ans=0;
			for(int i=1;i<=n;){
				if(a[i]==a[i+1]&&a[i]==1){
					ans++;
					i+=2;
					continue;
				}
				if(a[i]==0){
					ans++;
				}
				i++;
			}
			printf("%d",ans);
		}
		return 0;
	} 
	int ans=0,t=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}else{
			if(t==k){
				ans++;
				t=-1;
			}
			if(t==-1)t=a[i];
			else t^=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}
