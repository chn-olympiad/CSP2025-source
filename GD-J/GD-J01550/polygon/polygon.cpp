#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,a[5005],mod=998244353,cnt,ans,cnt1,f;
bool s[5005];
void dg(int bz){
	if(bz>n){
		cnt1=ans=f=0;
		for(int i=1;i<=n;i++){
			if(s[i]){
				f=max(f,a[i]);
				ans+=a[i];
				cnt1++;
			}
		}
		if(cnt1>=3)
		if(ans>f*2){
			cnt++;
		}
		return ;	
	}
	s[bz]=0;
	dg(bz+1);
	s[bz]=1;
	dg(bz+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dg(1);
	cout<<cnt%mod;
	return 0;
}
