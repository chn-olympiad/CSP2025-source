#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=1;
	int ni=n,n0=0;
	for(int i=1;i<=ni;i++){
		int a;
		cin>>a;
		if(a==0){
			n--;
			n0++;
		}
//		cout<<ans<<endl;
	}
	for(int i=n;i>=2;i--){
		ans=ans*i%998244353;
	}
	for(int i=n0;i>=2;i--){
		ans=ans*i%998244353;
	}
	cout<<ans;
}
