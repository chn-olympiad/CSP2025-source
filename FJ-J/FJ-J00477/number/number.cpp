#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zqq[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(ll i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			zqq[a[i]-48]++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=zqq[i];j++){
			cout<<i;
		}
	}
	return 0;
}
