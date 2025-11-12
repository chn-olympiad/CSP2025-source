#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],ans,sum,z[100000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	//
	for(int i=1;i<=n;i++){
		long long shang=1,q=1,sum=0,xia=1;
		for(int j=i;j>=1;j--){
			shang=(shang*j)%998244353;
			xia=(xia*q)%998244353;
			q++;
			sum=sum+shang/xia;
			sum=sum%998244353;
		}
		z[i]=sum;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			sum=0;
			for(int k=j+1;k<=n;k++){
				sum=a[i]+a[j]+a[k];
				if(sum>a[i]*2){
					ans+=(z[n-k]+1)%998244353;
				}else{
					if(k+1<=n){
						for(int g=k+1;g<=n;g++){
							sum+=a[g];
							if(sum>a[i]*2){
								ans+=z[n-g]+1;
								ans=ans%998244353;
								break;
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
