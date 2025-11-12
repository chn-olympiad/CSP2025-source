#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxmax=0;
	for(int i=1;i<=n;i++) maxmax=max(maxmax,a[i]);
	int w=1;
	if(maxmax==1){
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=i;j++)
				ans++;
			ans*=w;
			ans=ans%998244353;
		}
		cout<<ans;
	}else if(n==1 || n==2) cout<<"0";
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				for(int k=1;k<j;k++)
					if(a[i]+a[j]+a[k]>2*maxmax){
						ans++;
						ans=ans%998244353;
					}
		cout<<ans;
	}
	return 0;
}