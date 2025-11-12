#include "bits/stdc++.h"
using namespace std;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	if(k<2){
		for (int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++){
			if (a[i]==k)ans++;
		}
		cout<<ans<<"\n";
	}else{
		for (int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++){
			if (a[i]==k)ans++;
		}
		cout<<2*ans<<"\n";
	}
	
	return 0;
}
