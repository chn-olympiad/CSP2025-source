#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000100],n,c;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size()-1;
	for(ll i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++c]=s[i]-'0';
		}
	}
	sort(a+1,a+c+1);
	for(ll i=c;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
