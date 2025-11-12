#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],cnt,ans,j,l=1,gs;
bool f;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//特殊性质A
	for(int i=1;i<=n;i++){
		if(a[i]==1)cnt++;
		if(a[i]!=1&&a[i]!=0)f=1;
	} 
	if(cnt==n){
		cout<<n/2;
		return 0;
	}
	//特殊性质B 
	if(f!=1){
		if(k==1){
			cout<<cnt;
		}else{
			ans=n-cnt;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					gs=0;
					while(a[i]!=0){
						gs++;
						i++;
					}
					ans+=gs/2;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
