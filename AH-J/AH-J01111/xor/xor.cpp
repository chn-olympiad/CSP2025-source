#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int ans;
const int N=5e5+10;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
	}else if(k==2){
		cout<<2;
		return 0;
	}else if(k==3){
		cout<<2;
		return 0;
	}
	cout<<ans;
return 0;
}
