#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int n,a[10000],sum,ans;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>2*a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==4){
		a[5]=a[3];
		for(int i=0;i<=4;i++){
			if((sum-a[i])>2*a[i+1]) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==5){
		a[6]=a[4];
		int t;
		for(int i=0;i<=5;i++){
			for(int j=0;j<i;j++){
				if(j!=4) t=a[i+1];
				else t=a[3];
				if((sum-a[i]-a[j])>2*a[i+1]) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
}
