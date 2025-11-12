#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll cnt=0;
ll a[1234567];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	if(len==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		printf("%lld",a[i]); 
	} 
	return 0;
}
