#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	for(ll i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')	x+=s[i];	
	}
	sort(x.begin(),x.end());
	len=x.size();
	while(x[len-1]=='0'&&len-1>0){
		len--;
	}
	for(ll i=len-1;i>=0;i--){
		cout<<x[i];
	}
	return 0;
}
