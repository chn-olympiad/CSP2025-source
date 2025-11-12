#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
	freopen(seat,"w",seat.in);
	freopen(seat,"r",seat.out);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	ll n,m;
	ll r;
	cin>>n>>m;
	ll cur;
	ll scr[n*m+12];
	cin>>r;
	scr[0]=r;
	
	for(int i=1;i<n*m;i++){
		cin>>scr[i];
	}
	sort(scr,scr+n*m);
	
	for(int i=1;i<n*m;i++){
		if(scr[i]==r) cur=i;
	}
	cur=n*m-cur;
	ll lie=0;
	if(cur%m) lie=(cur/m)+1;
	else lie=cur/m;
	ll hang=0;
	if(lie%2!=0){
		if(cur%m==0) hang=m;
		else hang=cur%m;         //ÅÐ¶Ï¶¥¸ñ 
	}
	else{
		if(cur%m==1) hang=m;
		else hang=m-cur%m-1;
}
	cout<<lie<<" "<<hang;

	return 0;
}
