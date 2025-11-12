#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[500005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
int ans=0;
    for(int i=1;i<=n;i++){
    	ans+=n/i;
	}
	cout<<ans;
	return 0;
}//insert([]);
