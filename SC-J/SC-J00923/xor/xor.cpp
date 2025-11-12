#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans=0;
int a[510005];
int p[510005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)p[i]=p[i-1]^a[i];
	int l=1;
	while(l<=n){
		bool f=0;
		int ii=0;
		for(int i=l;i<=n;i++){
			for(int j=l;j<=i;j++){
				if((p[i]^p[j-1])==k){
					ans++;
					ii=i;
					f=1;
					break;
				}
			}
			if(f==1)
				break;
		}
		if(f==1){
			l=ii+1;
		}
		else break;
	}
	cout<<ans;
	return 0;
}