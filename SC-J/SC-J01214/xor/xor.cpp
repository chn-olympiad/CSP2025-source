#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000000+10;
int n,k,a[maxn],ans,maxx=INT_MIN,cnt;
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=(sum xor a[j]);
			if(sum==k){
				i=j;
				cnt++;
				break;
			}
		}
		if(cnt>=x) return 1;
	}
	if(cnt>=x) return 1;
	return 0;
}
bool cz(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return 0;
	}
	return 1;
} 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; maxx=max(maxx,a[i]);
		if(a[i]==1) cnt++;
	}
	if(k==1&&maxx==1) cout<<cnt;
	else if(cz()&&k==0) cout<<n/2;
	else{
		int l=0,r=n+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		cout<<ans;
	}
	return 0;
}