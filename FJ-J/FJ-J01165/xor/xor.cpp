#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,l=1,r,ans;
int a[N];
bool check(int x){
	int cnt=0;
	long long sum=0;
	bool f=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=k||sum<k){
			sum^=a[i];
			f=1;
		}
		if(sum>=k&&f){
			cnt++;
			sum=0;
			f=0;
		}
	}
	return cnt>=x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
