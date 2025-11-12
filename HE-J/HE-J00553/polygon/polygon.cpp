#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],ma,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>3){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans+=((i-j+1+i-j)*(i-j)+i-j+1)%998244353;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(a[i],ma);
			a+=a[i];
		}
		if(a>ma*2)cout<<1;
		else cout<<0;
	}
	
	return 0;
}

