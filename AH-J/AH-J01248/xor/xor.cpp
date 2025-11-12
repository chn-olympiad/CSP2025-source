#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)return 0;
	}
	return 1;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i]>1)return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check1() && k==0){
		cout<<n/2;
		return 0;
	}
	if(check2() && k<=1){
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++)ans+=a[i];
			cout<<ans;
		}
		else{
			int cnt=0,mx=0;
			for(int i=1;i<=n;i++){
				ans=0,cnt=0;
				for(int j=i;j<=n;j++){
					ans+=a[j];
					if(ans%2==0)cnt++,ans=0;
				}
				mx=max(mx,cnt);
			}
			cout<<mx;
		}
	}
	return 0;
}
