#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long  n,k,ans=0,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			cnt+=a[i];
		}else{
			cnt-=a[i];
		}
		if(cnt==k){
			ans++;
			cnt=0;
		}else if(a[i]==k){
			ans++;
			cnt=0;
		}
	}
	cout<<ans;
	return 0;
}
