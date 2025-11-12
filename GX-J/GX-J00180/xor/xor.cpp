#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[1048576]={};
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0,d=a[0];
	for(int i=0;i<n;i++){
		if(d==k){
			ans++;
			d=a[i];
			continue;
		}
		d=d^a[i];
	}
	cout<<ans;
	return 0;
}
