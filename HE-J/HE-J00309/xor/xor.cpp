#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
const int N=5e5+100;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool qy=1,yl=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			qy=0;
			break;
		}
	}
	if(qy){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0&&a[i]!=1){
			yl=0;
			break;
		}
	}
	if(yl){
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
			return 0;
		}
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
				if(a[i]==0){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
