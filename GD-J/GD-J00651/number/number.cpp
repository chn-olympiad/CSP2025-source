#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000005];
ll c;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[c++]=s[i]-'0';	
	}
	sort(a,a+c);
	for(ll i = c-1;i>=0;i--){
		printf("%lld",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
