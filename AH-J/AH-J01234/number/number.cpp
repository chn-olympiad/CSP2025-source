#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e5+10;
string s;
LL a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(LL i=0;i<(LL)s.size();i++)
		if(isdigit(s[i])) a[s[i]-'0']++;
	for(LL i=9;i>=0;i--)
		while(a[i]>0){
			printf("%lld",i);
			a[i]--;
		}
	return 0;
}
