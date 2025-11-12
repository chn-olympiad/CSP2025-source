#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long N=1e6+10;
string s;
ll a[N],now=0;
bool cmp(ll a,ll b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.length();
	for(ll i=0;i<len;i++){
		if(s[i]>=48&&s[i]<=57){
			a[now]=int(s[i]-48);
			now++;
		}
	}
	sort(a,a+now,cmp);
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	for(ll i=0;i<now;i++){
		cout<<a[i];
	}
	return 0;
}
