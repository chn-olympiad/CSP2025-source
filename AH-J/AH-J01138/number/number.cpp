#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[200];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	for(ll i=0;i<=len;i++){
		char k=s[i];
		if('0'<=k&&k<='9'){
			a[k-'0']++;
		}
	}
	string sum;
	for(int i=10;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
