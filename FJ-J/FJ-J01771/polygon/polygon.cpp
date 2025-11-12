#include<bits/stdc++.h> //CSP-J AK me
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005];
bool condition_of_one_is_the_numbers_of_e(int x){
	x-=(x&(-x)),x-=(x&(-x));
	return x;
} //why I use it?because I often retail past...
bool condition_of_two_is_the_edge(int x){
	int _=0,man_what_can_I_say=-24;
	for(int i=1;i<=n;i++){
		if(x&(1<<i-1)) _+=a[i],man_what_can_I_say=(a[i]>man_what_can_I_say?a[i]:man_what_can_I_say);
	}
	return _>2*man_what_can_I_say;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=7;i<(1<<n);i++){
		if(!condition_of_one_is_the_numbers_of_e(i)) continue;
		if(condition_of_two_is_the_edge(i)) ans++,ans=(ans>=mod?ans-mod:ans);
		
	}
	cout<<ans;
	return 0;
} 


























void AKAK(){
	long/* super super */long rp;
	while(1) rp++;
	return;
}












