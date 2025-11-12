#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=5e5+30;

int a[N];
int sum[N];
int n,k;

bool ok(int l,int r){
	return (sum[r]^sum[l-1])==k;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool opt1=1,opt2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			opt1=0;
		}
		if(a[i]!=0&&a[i]!=1){
			opt2=0;
		}
		sum[i]=(sum[i-1]^a[i]);
	}
	if(opt1){
		if(k==0){
			cout<<n<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}else if(opt2){
		if(k!=0&&k!=1){
			cout<<0<<'\n';
		}else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=(a[i]==1);
			}
			cout<<ans<<'\n';
		}else if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}else if(a[i]==1&&a[i+1]==0&&a[i+2]==1){
					ans++;
					i+=2;
				}else if(a[i]==0){
					ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//ygg pls 