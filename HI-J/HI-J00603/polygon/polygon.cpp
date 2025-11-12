#include<bits/stdc++.h>
using namespace std;
long long n,a[1101101],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[i]+a[j]>a[l]){
					int cnt=1,cnt1=1;
					for(int k=1;k<=j-i;k++){
						for(int r=j-i;r>=k;r--){
							cnt*=r;
						}
						for(int r=1;r<=k;r++){
							cnt1*=r;
						}
						ans=ans+cnt/cnt1;
						ans%=998244353;
					}
					cnt=1;
					cnt1=1;
					for(int k=1;k<=l-j;k++){
						for(int r=l-j;r>=k;r--){
							cnt*=r;
						}
						for(int r=1;r<=k;r++){
							cnt1*=r;
						}
						ans=ans+cnt/cnt1;
						ans%=998244353;
					}
				}
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
