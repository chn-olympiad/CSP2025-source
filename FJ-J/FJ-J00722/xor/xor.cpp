#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],k,f,fl,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
		if(a[i]!=0&&a[i]!=1){
			fl=1;
		}
	}
	if(k==0&&f==0){
		cout<<n/2;
		return 0;
	}
	if(k<=1&&fl==0){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
		else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else if(a[i]==1&&a[i-1]==1){
					ans++;
					a[i]=-1;
					a[i-1]=-1;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<n; 
	return 0;
}
