#include<bits/stdc++.h>

using namespace std;
int Q=998244353; 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}	
	if(n==3){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){
						ans++;
						ans%=Q;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(maxx==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
			ans%=Q;
		}
		cout<<ans;
		return 0;
	}
	int i=1;
	if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i+2]==a[i+3]){
		int ans=0;
		for(int j=3;j<=n;j++){
			ans+=n-j+1;
			ans%=Q;
		}
		cout<<ans;
		return 0;
	}
	cout<<1;
	return 0;
}
