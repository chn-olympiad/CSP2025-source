#include<bits/stdc++.h>
using namespace std;
const long long mod=998242353;
long long n,a[5010],ans=0;
void baoli(int id,long long h,long long mx,int sl){
	if(id==n){
		if(h>2ll*mx&&sl>=3)ans=(ans+1ll)%mod;
		return;
	}
	baoli(id+1,h,mx,sl);
	baoli(id+1,h+a[id],max(mx,a[id]),sl+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	baoli(0,0ll,0ll,0);
	cout<<ans;
	return 0;
}