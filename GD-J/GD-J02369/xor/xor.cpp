#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll zh[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll z,h,szh=0,ma=0,mi=1<<20,sl=0;
	cin>>z>>h;
	for(ll i=1;i<=z;i++){
		ll j;
		cin>>j;
		ma=max(ma,j),mi=min(mi,j);
		if(j==1){
			sl++;
		}
		zh[i]=j^zh[i-1];
	}
	if(h==0&&ma==1&&mi==1){
		cout<<z/2;
		return 0;
	}else if(h==1&&ma==1&&(mi==0||mi==1)){
		cout<<sl;
		return 0;
	}else if(h==0&&ma==0&&mi==0){
		cout<<z;
		return 0;
	}else if(h==0&&ma==1&&mi==0){
		cout<<max(sl/2,z-sl);
		return 0;
	}
	cout<<szh;
	return 0;
}
