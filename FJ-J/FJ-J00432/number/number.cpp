#include<bits/stdc++.h>
#define  ll  long long
using namespace std;
const int N=INT_MAX;
string s;
ll a[15],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll i=s.length();
	while(i>=0){
		    if(s[i]>='0' && s[i]<='9'){
		    	a[s[i]-'0']+=1;
	    	}
	    	i--;
	}
	for(ll i=10;i>=0;i--){
		if(a[i]>0){
			ll o=a[i];
			while(o>0){
				cout<<i;
				o--;
		    }
		}
    }
	return 0;
}
