#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll a[1000010];
ll cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll m=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[m++]=s[i]-'0';
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	return 0;
} 
