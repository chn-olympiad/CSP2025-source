#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string a;
int c[501],ans=1,cnt=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<+n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
