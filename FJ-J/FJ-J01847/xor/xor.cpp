#include<bits/stdc++.h>
using namespace std;
int a[500009],sum[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i,j,k,ans=0,flag=1,flag1;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		if(!a[i]) flag=0;
	}
	if(flag==1){
		ans=n/2;
	}
	else if(!flag){
		if(!k){
			for(i=1;i<=n;i++){
				if(!a[i]){
					ans++;
				}
				if(a[i]==a[i+1]&&a[i+1]){
					ans++;
					i++;
				}
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(a[i]){
					ans++;
				}
				else if(!a[i]&&a[i+1]){
					ans++;
					i++;
				}
			}
		}	
	}
	else{
		for(i=1;i<=n;i++){
			j=i,flag1=0;
			while(j<=n){
				if(sum[j]^sum[i-1]==k){
					ans++;
					flag1=1;
					break;
				}
				j++;
			}
			if(flag1) i=j+1;
		}
	}
	printf("%d",ans);
	return 0;
}
