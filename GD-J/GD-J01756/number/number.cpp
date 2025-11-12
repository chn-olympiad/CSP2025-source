#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(ll x, ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	ll num[1145140];
	ll l=0;
	for(ll i = 0; i < a.size(); i++){
		if(a[i]>='0'&&a[i]<='9')num[l++]=a[i]-'0';
	}
	sort(num,num+l,cmp);
	for(ll i = 0; i < l; i ++){
		cout<<num[i];
	}
	return 0;
} 
