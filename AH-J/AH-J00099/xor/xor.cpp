#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main (){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,k,ans=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if (k==0){
		int cnt=-1;
		for (int i=1;i<=n;i++){
			if (a[i]==0) ans++;
			else {
				if (i-cnt==1) {
					ans++;
				}
				else cnt=i;
			} 
		}
	}
	else {
		for (int i=1;i<=n;i++){
			if (a[i]==1) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
