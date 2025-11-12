#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
int cnt[11];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	n=s.size()-1;
	for(int i=1;i<=n;i++){
		ll u=s[i]-'0';
		if(0<=u&&u<=9)cnt[u]++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cnt[i]--;
			cout<<i;
		}
	}
	return 0;
}