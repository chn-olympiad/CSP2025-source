#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum1,sum0,ans,a[500005];
bool b[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i])	sum1++;
    	else	sum0++;
	}
	int i=1;
	if(k==0){
		while(i<=n){
			if(a[i]==a[i+1]&&a[i]==1){
				ans++;
				i+=2;	
			}
			else if(a[i]==0){
				ans++;
				i++;
			}
			else{
				i++;
			}
		}
	}
	else{
		cout<<sum1;
		return 0;
	}
	cout<<ans;
	return 0;
}  