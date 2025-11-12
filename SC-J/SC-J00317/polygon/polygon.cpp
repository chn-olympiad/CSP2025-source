#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
long long jc[5001];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polugon.out","w",stdout);
	jc[0]=1;
	jc[1]=1;
	for(int i=2;i<=5001;i++){
		jc[i]=jc[i-1]*i%998244353;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if(n==3){
		if((a[1]+a[2])>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		ans=0;
		for(int i=n;i>=3;i--){
			for(int j=i-1;j>=2;j--){
				for(int o=j-1;o>=1;o--){
					if((a[j]+a[o])>a[i]){
						ans++;
						ans=ans%998244353;
						for(int q=1;q<=j-o-1;q++){
							ans+=((jc[j-o-1]/jc[j-o-1-q])/jc[q])%998244353;
						}
					}
				}
			}
		}
		cout<<ans%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 