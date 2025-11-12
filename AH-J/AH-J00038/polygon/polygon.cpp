#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long maxnai=0,sum=0;
			for(int k=i;k<=j;k++){
				maxnai=max(maxnai,a[k]);
				sum=sum+a[k];
			}
			if(maxnai*2<sum){
				long long p=sum;
				ans++;
				for(int k=j+1;k<=n;k++){
					if(a[k]*2<p+a[k]){
						ans++;
					}
				}
			}
		}
	}
	cout<<(ans+2)%998%244%353;
	return 0;
}
