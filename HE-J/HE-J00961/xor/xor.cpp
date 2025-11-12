#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(nullptr),cin.tie(nullptr);
using namespace std;

const int N=5e5+10;
int n,k,a[N];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios;
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	bool f=1,f2=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)	f=0;
		if(a[i]>1)	f2=0;
	}
	if(f&&!k){
		cout<<n/2;
		return 0;
	}
	if(f2){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1)	{
					if(a[i+1]==1){
						ans++;
						i++;
					}
				}
				else ans++;
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)	ans++;
			}
		}
		cout<<ans;
		return 0;
	}
}
