#include<bits/stdc++.h>
using namespace std;
long long n,r,a[1000005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(r>1){
		cout<<"!!!        I AK IOI        !!!(T^T)";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(r){
			if(a[i]==1)ans++;
		}else{
			if(a[i]==0)ans++;
			else{
				if(a[i+1]==0){
					ans++;
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
