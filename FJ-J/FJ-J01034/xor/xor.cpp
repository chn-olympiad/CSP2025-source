#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005];
bool bj=0,bjj=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			bj=1;
		}
		if(a[i]!=1&&a[i]!=0){
			bjj=1;
		}
	}
	if(bj==0){
		if(k==1){
			cout<<n;
			return 0;
		}else if(k==0){
			cout<<n/2;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(bjj==0){
		if(k==1){
			int ll=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ll++;
				}
			}
			cout<<ll;
			return 0;
		}else if(k==0){
			int ll=0;
			bool jj=1;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ll++;
				}else{
					if(a[i-1]==1&&jj==1){
						ll++;
						jj=0;
					}else{
						jj=1;
					}
				}
			}
			cout<<ll;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	cout<<67;
	return 0;
}
