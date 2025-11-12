#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1100];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll zs=1;
	ll n=s.size();
	for(ll i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[zs]=s[i]-'0';
			zs++;
		}
	sort(a+1,a+zs,cmp);
	for(ll i=1;i<=zs-1;i++){
		cout<<a[i];
	}	
	return 0;
}