#include<bits/stdc++.h>
using namespace std;
int n,a[5005],com,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	com=(2*a[n]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=j+1;q<=n;q++){
				if(a[i]+a[j]+a[q]>com) ans++;
				if(q==n) break;
				else{
					for(int z=q+1;z<=n;z++){
						if(a[i]+a[j]+a[q]+a[z]>com) ans++;
						if(z==n) break;
						else{
							for(int m=z+1;m<=n;m++){
								if(a[i]+a[j]+a[q]+a[z]+a[m]>com) ans++;
							}
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
