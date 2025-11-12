#include<bits/stdc++.h>
using namespace std;
int a[5005];
int dp[5005];
int cnt1,cnt2,ans;
int n;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>maxx){
			maxx=a[i];
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				cnt1+=a[k];
			}
			if(cnt1>(2*maxx)&&i>=3){
				ans++;
			}
			cnt1=0;
		}
	}
	maxx=0;
	for(int i=1;i<=n;i++){
		if(a[i]>maxx){
			maxx=a[i];
		}
		for(int j=i;j<=n;j++){
			for(int k=n;k>j;k--){
				cnt2+=a[k];
			}
			if(cnt2>(2*maxx)&&i>=3){
				ans++;
			}
		}
	}
	cout<<ans;
}
