#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N=1e3+5;
string s;
LL a[N],cnt;
bool cmp(const LL &x,const LL &y){return x>y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto ch:s) if(ch>='0'&&ch<='9') a[++cnt]=ch-'0';
	sort(a+1,a+cnt+1,cmp);
	for(LL i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
