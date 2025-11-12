#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[1000010],l,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(ll i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(ll i=k;i>=1;i--) printf("%lld",a[i]);
	return 0;
}
