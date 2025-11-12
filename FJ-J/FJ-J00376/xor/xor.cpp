#include <bits/stdc++.h>
using namespace std;
const int maxn=500003;
int n;
long long a[maxn],k;
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(sum==k&&i!=1){
			ans++,sum=a[i];
		}else{
			sum = (sum ^ a[i]) ;
		}
	}
	if(sum==k){
		ans++;
	}
	int ans1=0;sum=0;
	for(int i=n;i>=1;i--){
		if(sum==k&&i!=n){
			ans1++,sum=a[i];
		}else{
			sum = (sum ^ a[i]) ;
		}
	}
	if(sum==k){
		ans1++;
	}
	cout<<max(ans1,ans);
	return 0;
}
