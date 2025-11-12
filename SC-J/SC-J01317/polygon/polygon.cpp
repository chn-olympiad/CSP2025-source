#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
bool isok(int x,int y,int z){
	int mx=max(x,max(y,z));
	int sum=x+y+z;
	if(sum>2*mx) return true;
	return false;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(isok(a[i],a[j],a[k])) {
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}