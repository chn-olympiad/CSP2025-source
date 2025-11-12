#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int a[600000];
bool A=true,B=true;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=false;
		}
		if(a[i]>1){
			B=false;
		}
	}
	if(k==0&&A){
		cout<<n/2;
		return 0;
	}else if(k==0&&B){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}else if(a[i]==1&&a[i+1]==1&&i!=n){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}else if(k==1&&B){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i!=n&&a[i]!=a[i+1]){
				ans++;
				i++;
			}else if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

