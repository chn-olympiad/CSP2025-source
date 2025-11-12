#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N],l,r,mid,ans;
bool check(int tot){
	int i=1,temp=0,cnt=0;
	while(i<=n){
		if(a[i]==k){
			temp=0;
			cnt++;
		}else if((temp^a[i])==k){
			temp=0;
			cnt++;
		}else{
			temp^=a[i];
		}
		i++;
	}
	return cnt>=tot;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	l=1,r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;

	return 0;
}