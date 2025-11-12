#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll len,ans,tmp,m[17];
string a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;len = a.length();
	for(ll i = 0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			tmp = a[i]-'0';
			m[tmp]++;
		}
	}
	for(ll i = 9;i>=0;i--){
		for(ll j = 1;j<=m[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}
