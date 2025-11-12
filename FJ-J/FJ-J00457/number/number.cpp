#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
ll a[N];
string s;
bool cmp(ll aa,ll b){
	return aa>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll cnt=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}

