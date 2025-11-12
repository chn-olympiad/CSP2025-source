#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+100;
int n;
ll k,x,last=0;
ll ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		last=last^x;
		if(last==k){
			ans++,last=0;
		}else if(x==k){
			ans++,last=0;
		}
	}
	cout<<ans;
	return 0;
}
