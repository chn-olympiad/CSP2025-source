#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--){
		for(int j=i-1;j>=2;j--){
			int x=a[i]+a[j];
			for(int k=j-1;k>=1;k--){
				x+=a[k];
				if(x>a[i]*2){
					++ans;
					if(k-1>=1){
						++ans;
					}
					int x=1;
					for(int l=1;l<k-1;l++){
						x*=2;
						++x;
					}
					ans+=x;
					ans%=998244353;
					x-=a[k];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
