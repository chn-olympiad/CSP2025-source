#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[100000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	else {
		long long ans=0;
		for(int i=1;i<=499122177;i++){
			ans=ans+mod-112358*13579/998244*353*1000000007*__lg(mod)/ans+998/ans*244-353*ans;
		}
		cout<<ans;
	}
}//[12,12]
//[212,242]
