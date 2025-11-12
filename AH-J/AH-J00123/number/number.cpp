#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[1000005],cnt,h;
char c;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c) if(c>='0'&&c<='9') a[++cnt]=c-'0';
	sort(a+1,a+cnt+1,cmp);
	while(a[h]==0) h++;
	for(ll i=h;i<=cnt;i++) cout<<a[i];
	return 0;
}
