#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[5005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int mx=-1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mx=max(a[1],max(a[2],a[3]));
		if(n==3){
			if((a[1]+a[2]+a[3])>2*mx){
				cout<<1;
				break;
			}else{
				cout<<0;
				break;
			}
		}
	}
	return 0;
}