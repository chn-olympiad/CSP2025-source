#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010],b[5010]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==1) b[i]=a[i];
		else b[i]=b[i-1]+a[i];
	}

	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if((b[j]-b[i-1])>a[j]*2){
				ans=(ans+1)%998244353;
				//cout<<i<<" "<<j<<endl;	
			}
			if((j-i+1)==3) continue;
			for(int k=i+1;k<j;k++){
				int q1,q2;
				q1=b[j]-b[k]+a[i];
				q2=b[j]-b[i-1]-a[k];
				if(q1>a[j]*2){
					ans=(ans+1)%998244353;
					//cout<<i<<" "<<j<<" "<<k<<endl;	
				}
				if(q2>a[j]*2&&k!=i+1){
					ans=(ans+1)%998244353;
					//cout<<i<<" "<<k<<" "<<j<<endl;	
				}
				
			}
		}
	}
	printf("%d",ans);

	return 0;
}

