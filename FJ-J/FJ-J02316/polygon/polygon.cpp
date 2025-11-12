#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],t[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=t[i-1]+a[i];
	}
	long long ans=0;
	if(n==3){
		int Max=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>Max*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==4){
		int Max=max(a[1],max(a[2],max(a[3],a[4])));
		if(a[1]+a[2]+a[3]+a[4]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[4]));
		if(a[1]+a[2]+a[4]>Max*2) ans++;
		Max=max(a[2],max(a[3],a[4]));
		if(a[2]+a[3]+a[4]>Max*2) ans++;
		cout<<ans;
	}else if(n==5){
		int Max=max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
		if(a[1]+a[2]+a[3]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],a[4])));
		if(a[1]+a[2]+a[3]+a[4]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],a[5])));
		if(a[1]+a[2]+a[3]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[4],a[5])));
		if(a[1]+a[2]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[3],max(a[4],a[5])));
		if(a[1]+a[3]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[2],max(a[3],max(a[4],a[5])));
		if(a[2]+a[3]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[4]));
		if(a[1]+a[2]+a[4]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[5]));
		if(a[1]+a[2]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[3],a[4]));
		if(a[1]+a[3]+a[4]>Max*2) ans++;
		Max=max(a[1],max(a[3],a[5]));
		if(a[1]+a[3]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[4],a[5]));
		if(a[1]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[2],max(a[3],a[4]));
		if(a[2]+a[3]+a[4]>Max*2) ans++;
		Max=max(a[2],max(a[3],a[5]));
		if(a[2]+a[3]+a[5]>Max*2) ans++;
		Max=max(a[2],max(a[4],a[5]));
		if(a[2]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[3],max(a[4],a[5]));
		if(a[3]+a[4]+a[5]>Max*2) ans++;
		cout<<ans;
	}else if(n==6){
		int Max=max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))));
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
		if(a[1]+a[2]+a[3]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],max(a[4],a[6]))));
		if(a[1]+a[2]+a[3]+a[4]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],max(a[5],a[6]))));
		if(a[1]+a[2]+a[3]+a[5]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[4],max(a[5],a[6]))));
		if(a[1]+a[2]+a[4]+a[5]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[3],max(a[4],max(a[5],a[6]))));
		if(a[1]+a[3]+a[4]+a[5]+a[6]>Max*2) ans++;
		Max=max(a[2],max(a[3],max(a[4],max(a[5],a[6]))));
		if(a[2]+a[3]+a[4]+a[5]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],a[4])));
		if(a[1]+a[2]+a[3]+a[4]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],a[5])));
		if(a[1]+a[2]+a[3]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[3],a[6])));
		if(a[1]+a[2]+a[3]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[4],a[5])));
		if(a[1]+a[2]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[2],max(a[4],a[6])));
		if(a[1]+a[2]+a[4]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[3],max(a[4],a[5])));
		if(a[1]+a[3]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[3],max(a[4],a[6])));
		if(a[1]+a[3]+a[4]+a[6]>Max*2) ans++;
		Max=max(a[2],max(a[3],max(a[4],a[5])));
		if(a[2]+a[3]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[2],max(a[3],max(a[4],a[6])));
		if(a[2]+a[3]+a[4]+a[6]>Max*2) ans++;
		Max=max(a[3],max(a[4],max(a[5],a[6])));
		if(a[3]+a[4]+a[5]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[4]));
		if(a[1]+a[2]+a[4]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[5]));
		if(a[1]+a[2]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[2],a[6]));
		if(a[1]+a[2]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[3],a[4]));
		if(a[1]+a[3]+a[4]>Max*2) ans++;
		Max=max(a[1],max(a[3],a[5]));
		if(a[1]+a[3]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[3],a[6]));
		if(a[1]+a[3]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[4],a[5]));
		if(a[1]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[1],max(a[4],a[6]));
		if(a[1]+a[4]+a[6]>Max*2) ans++;
		Max=max(a[1],max(a[5],a[6]));
		if(a[1]+a[5]+a[6]>Max*2) ans++;
		Max=max(a[2],max(a[3],a[4]));
		if(a[2]+a[3]+a[4]>Max*2) ans++;
		Max=max(a[2],max(a[3],a[5]));
		if(a[2]+a[3]+a[5]>Max*2) ans++;
		Max=max(a[2],max(a[3],a[6]));
		if(a[2]+a[3]+a[6]>Max*2) ans++;
		Max=max(a[2],max(a[4],a[5]));
		if(a[2]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[2],max(a[4],a[6]));
		if(a[2]+a[4]+a[6]>Max*2) ans++;
		Max=max(a[3],max(a[4],a[5]));
		if(a[3]+a[4]+a[5]>Max*2) ans++;
		Max=max(a[3],max(a[4],a[6]));
		if(a[3]+a[4]+a[6]>Max*2) ans++;
		Max=max(a[4],max(a[5],a[6]));
		if(a[4]+a[5]+a[6]>Max*2) ans++;
		cout<<ans;
	}else{
		for(int k=3;k<=n;k++){
			for(int i=1;i<=n-k+1;i++){
				for(int l=0;l+k+i-1<=n;l++){
					int Max=a[i];
					for(int j=i+l+1;j<=i+l+k-1;j++){
						Max=max(Max,a[j]);
					}
					if(a[i]+t[i+l+k-1]-t[i+l]>Max*2) ans++;
				}
			}
		}
		cout<<ans%mod;
	}
	return 0;
}
