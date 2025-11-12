#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int ans=1;
	for(int i=n;i>0;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
