#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],flag=1,flag1=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flag=0;
		}
		if(a[i]>1){
			flag1=0;
		}
	}
	if(flag==1){
		if(k==0){
			printf("%d",n/2);
		}else if(k==1){
			printf("%d",n);
		}
		return 0;
	}
	if(flag1==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			printf("%d",ans);
		}else if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]){
					ans++;
					i+=2;
				}else if(a[i]==1&&a[i+2]==1&&a[i+1]==0){
					ans++;
					i+=3;
				}
			}
			printf("%d",ans);
		}
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}else if(a[i]==a[i+1]){
				ans++;
				i+=2;
			}
		}
		printf("%d",ans);
	}
	for(int i=1;i<=n;i++){
		if(i==k){
			ans++;
			continue;
		}
		int b=a[i];
		for(int j=i+1;j<=n;j++){
			b=b^a[j];
			if(b==k){
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}