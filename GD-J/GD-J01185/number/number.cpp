#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
string s;
ll a[1000000];
ll x=0,su=0;
char q[]={'0','1','2','3','4','5','6','7','8','9'};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll l=s.size();
	for(ll i=0;i<s.size();i++){
		for(int j=0;j<10;j++){
			if(s[i]==q[j]){
				a[x]=j;
				x++;
			}
		}	
	}
	for(ll i=0;i<x;i++){
		for(ll j=0;j<x-i-1;j++){
			if(a[j]<a[j+1]){
				ll k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
	}
	for(ll i=0;i<x;i++){
		su=su*10+a[i];
	}
	cout<<su;
	
	return 0;
}
