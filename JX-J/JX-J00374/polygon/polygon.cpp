#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5010];
int b[5010];
int sum,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		for(int i=3;i<=n;i++){
			int sum=a[i];
			for(int j=1;j<=i;j++){
				sum+=a[j];
				if(sum>2*a[i]){
					ans+=i-j+1;
					break;
				}
			}
		}
		cout<<ans%998244353;
	}
	return 0;
}
