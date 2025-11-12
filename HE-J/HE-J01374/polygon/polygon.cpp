#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5001];
const int MOD=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+1+n);
	int cl[5001];
	for(int i=3;i<=n;i++){
		for(int j=1;j<i;j++){
			cl[i]+=a[j];
		}
	}
	for(int i=3;i<=n;i++){
		if(cl[i]<a[i]) continue;
		int rc=cl[i]-a[i];
		int yj=0;
		for(int j=1;j<i;j++){
		int jsq=0;
	       for(int k=i-1;k>j;k++){
	       	if(jsq+a[k]>=rc){
	       		break;
			   }else{
			   	jsq+=a[k];
			   	ans++;
			   	yj++;
			   }
		   }
		}
		if(yj==0){
			ans++;
		}
	}
     cout<<ans%MOD;
	return 0;
}
