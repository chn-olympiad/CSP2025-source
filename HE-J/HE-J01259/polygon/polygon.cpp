#include<bits/stdc++.h>
using namespace std;
int n,m[10010];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	if(n>=4){
		for(int i=n;i>1;i--){
			ans=(ans+(i*(i-1)));
			ans=ans%998244353;
		}
		cout<<ans/2;
		return 0;
	}
	if(m[1]+m[2]>m[3])cout<<"1";
	else cout<<"0";
	return 0;
}
