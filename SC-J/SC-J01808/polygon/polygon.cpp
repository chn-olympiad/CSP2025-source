#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=3,ans=0;
	while(cnt<=n){
		if(cnt==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if(a[i]+a[j]>a[k]){
							ans++;
							ans%=998244353;
						}else{
							break;
						}
					}
				}
			}
		}else if(cnt==4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int m=k+1;m<=n;m++){
							if(a[i]+a[j]+a[k]>a[m]){
								ans++;
								ans%=998244353;
							}else{
								break;
							}
						}
					}
				}
			}
		}else{
			ans=ans+n-cnt+1;
		}
		ans%=998244353;
		cnt++;
	}
	cout<<ans;
	return 0;
}
//polygon