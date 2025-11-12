#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
string s;
ll cnt[15],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size(); 
	for(ll i=0;i<len;i++){
		char ch=s[i];
		if('0'<=ch and ch<='9') cnt[ch-48]++;
	}
	for(ll i=9;i>=0;i--){
		while(cnt[i]>0){
			cnt[i]--;
			cout<<i; 
		}
	}
	return 0;
}