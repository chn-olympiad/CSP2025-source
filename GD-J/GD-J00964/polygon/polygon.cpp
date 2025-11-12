#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
queue<int>q; 
int mod=99824435;
int ans,cnt;
signed main(){
	freopen("polgon.in","r",stdin);
	freopen("polgon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		} 
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
		}
	}
	if(cnt==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		} 
		ans+=mod;
		ans-=(n*(n+1)/2+1)%mod;
		ans%=mod;
		cout<<ans;
		return 0;
	}
	q.push(a[1]);
	q.push(a[2]);
	q.push(a[1]+a[2]);
	for(int i=3;i<=n;i++){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			if(q.front()>a[i]){
				ans++;
				ans%=mod;
			}
			q.push(q.front());
			q.push(q.front()+a[i]);
			q.pop();
		}
		q.push(a[i]);
	}
	cout<<ans;
	return 0;
}

