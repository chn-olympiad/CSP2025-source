#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll ans=s.size();
	ll a[10086];
	ll sum=0;
	for(int i=0;i<ans;i++){
		if(s[i]==57){
			a[sum]=9;
			sum++;
		}
		
		if(s[i]==56){
			a[sum]= 8;
			sum++;
		}
		
		if(s[i]==55){
			a[sum]=7;
			sum++;
		}
		
		if(s[i]==54){
			a[sum]=6;
			sum++;
		}
		if(s[i]==53){
			a[sum]=5;
			sum++;
		}
		if(s[i]==52) {
			a[sum]=4;
			sum++;
		}
		if(s[i]==51){
			a[sum]=3;
			sum++;
		}
		if(s[i]==50){
			a[sum]=2;
			sum++;
		}
		if(s[i]==49){
			a[sum]=1;
			sum++;
		}
		if(s[i]==48){
			a[sum]=0;
			sum++;
		}
	}
	sort(a,a+sum);
	for(ll i=sum-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
