#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[1000005],p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++p]=(s[i]-'0');
	}
	sort(a+1,a+1+p);
	for(ll i=p;i>=1;i--) cout<<a[i];
	return 0;
} 
