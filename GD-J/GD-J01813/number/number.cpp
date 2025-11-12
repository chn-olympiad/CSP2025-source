#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
string s;
ll a[N],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')a[++l]=(ll)(s[i]-'0');
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--){
		printf("%lld",a[i]);
	}
	return 0;
} 
