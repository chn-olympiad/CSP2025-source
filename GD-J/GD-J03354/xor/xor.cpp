#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,k,a[N],b[N];
void solve1(){
	int ans=0,cnt=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) {
			ans++;
			cnt=0;
		}
		else {
			cnt++;
			if(cnt==2){
				cnt=0;
				ans++;
			}
		}
	}
	cout<<ans;
}
void solve2(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) ans++;
	}
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	 
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(k<=0){
		solve1();
		return 0;
	}	
	
	if(k==1){
		solve2();
		return 0;
	}
	
	int ans=0;
	
	map <int,int> mp;
	mp[0]++;
	for(int i=1;i<=n;i++){
		b[i]=a[i]^b[i-1];
//		cout<<b[i]<<" ";
		if(mp[(b[i]^k)]||a[i]==k) mp.clear(),mp[0]++,ans++,b[i]=0;
		else mp[(b[i])]++;
	}
	
	cout<<ans;
	return 0;
}
