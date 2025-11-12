#include <bits/stdc++.h>
using namespace std;
int n;
int a[5055];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool flag=1;
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]!=a[i-1] && i!=1)flag=0;
	}
	if (n==3){
		int Maxn=max(max(a[1],a[2]),a[3]);
		if ((a[1]+a[2]+a[3])>(2*Maxn))printf("1");
		else printf("0");
	}else if (n==4){
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				for (int k=j+1;k<=n;k++){
					int Maxn=max(max(a[i],a[j]),a[k]);
					if ((a[i]+a[j]+a[k])>(2*Maxn))ans++;					
				}
			}
		}
		int Maxn=max(max(a[1],a[2]),max(a[3],a[4]));
		if ((a[1]+a[2]+a[3]+a[4])>(2*Maxn))ans++;
		printf("%d",ans);
	}else if (n==5){
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				for (int k=j+1;k<=n;k++){
					int Maxn=max(max(a[i],a[j]),a[k]);
					if ((a[i]+a[j]+a[k])>(2*Maxn))ans++;					
				}
			}
		}		
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				for (int k=j+1;k<=n;k++){
					for (int l=k+1;l<=n;l++){
						int Maxn=max(max(a[i],a[j]),max(a[k],a[l]));
						if ((a[i]+a[j]+a[k]+a[l])>(2*Maxn))ans++;			
					}				
				}
			}
		}	
		int Maxn=max(max(max(a[1],a[2]),max(a[3],a[4])),a[5]);
		if ((a[1]+a[2]+a[3]+a[4]+a[5])>(2*Maxn))ans++;
		printf("%d",ans);			
	}else if (flag==1){
		int ans=0;
		for (int i=3;i<=n;i++){
			int ans1=1;
			for (int j=n;j>n-i+1;j--)ans1*=j;
			for (int j=1;j<=i;j++)ans1/=j;
			ans+=ans1;
			ans%=998244353;
		}printf("%d",ans);
	}
	return 0;
}

