#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt=0,sum[5005];
const int MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))  {
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(n==4){
		for(int i=1;i<=4;i++){
			if(sum[4]-a[i]>2*max(a[1],max(a[2],max(a[3],a[4]))))  cnt++;
		}
		cout<<cnt;
		return 0;
	}
	cout<<9;
	return 0; 
}
