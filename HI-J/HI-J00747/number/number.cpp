#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.length();
	string temp;
	for(ll i=0;i<len;i++){
		if(len==1){
			cout<<s[i];
			return 0;
		}
		if(s[i]>='0'&&s[i]<='9'){
			temp+=s[i];
		}
	}
	for(int i=0;i<temp.length();i++){
		a[i]=temp[i]-'0';
	}

	for(ll i=0;i<temp.length();i++){
		for(ll j=0;j<temp.length();j++){
			if(a[i]<=a[j]){
			ll t=a[i];
			a[i]=a[j];
			a[j]=t;
			}
		}
	}
	for(ll i=temp.length()-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
