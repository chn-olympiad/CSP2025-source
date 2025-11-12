#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
string s;
ll a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll p=s.size();
	for(ll i=0;i<p;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		while(a[j]--){
			cout<<j;
		}
	}
	return 0;
}
