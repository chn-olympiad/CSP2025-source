#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL N = 1e6;
LL a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	LL n=0;
	LL l=s.size();
	for(LL i = 0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(LL i = n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
