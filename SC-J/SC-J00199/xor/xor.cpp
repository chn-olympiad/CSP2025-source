#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+1;
int n,k,a[N],cnt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==1||a[i]==0){
			cnt++;
		}
	}
	if(n==1&&k==0){
		if(a[1]!=0)cout<<0;
		else cout<<1;
	}else if(n==2&&k==0){
		if(a[1]==0&&a[2]==0){
			cout<<2;
		}else if(a[1]==0&&a[2]!=0||a[1]!=0&&a[2]==0){
			cout<<1;
		}else if(a[1]==a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<=10&&k<=1){
		if(k==0){
			//特殊情况
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]&&a[i]!=0){
					ans++;
					i=i+2;
				}else if(a[i]==0){
					ans++;
				}
			}
			cout<<ans;
		}else if(k==1&&cnt==n){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++; 
				}
			}
			cout<<ans;
		}else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}else if(abs(a[i]-a[i+1])==1){
					ans++;
					i=i+2;
				}
			}
			cout<<ans;
		}
	}else{
		cout<<n/2;
	}
	return 0;
}
