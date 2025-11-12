#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
string s;
ll n=0,a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<((ll)s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n,greater<int>());
	for(ll i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
