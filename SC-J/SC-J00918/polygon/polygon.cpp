#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mx1=-1e9,sum1=0; 
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx1=max(mx1,a[i]);
		sum1+=a[i];
	}
	if(n==3){
		if(sum1<=mx1*2)cout<<0;
		else cout<<1;
		return 0;
	}else if(mx1==1){
		ans=((n-1)*(n-2))/2;
		ans%=998244353;
		cout<<ans;
		return 0;
	}else if(n<=20){
		int mx=-1e9,sum=0;
		for(long long i=7;i<=65536;i++){
			int indx=0;
			for(int j=1;j<=n;j++){
				bool x=i>>(n-j);
				if(x==1){
					indx++;
					mx=max(mx,a[i]);
					sum+=a[i];
				}
			}
			if(indx>=3){
				if(sum>mx*2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}