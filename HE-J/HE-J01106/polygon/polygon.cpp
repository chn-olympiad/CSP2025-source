#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int a[N];
int n,tot,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	tot+=a[i];
	}
	if(tot<=1){
		cout<<0;
		return 0;
	}
    int k=1;
    for(int i=2;i<=n+1;i++){
    	k*=2;
	}
    for(int i=1;i<=k;i++){
    	int z=0,maxn=-1,l=0;
    	for(int j=0;j<n;j++){
    		
    		if(i&(1<<j)){
    			l++;
    		    z+=a[j+1];
    		    maxn=max(maxn,a[j+1]);
		    }
		}
		if(z>maxn*2&&l>=3)ans++;
	}
	cout<<ans;
}

/*


*/
