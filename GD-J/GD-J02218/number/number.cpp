#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000010],t;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-48;
	sort(a+1,a+1+t,greater<ll>());
	for(int i=1;i<=t;i++)
	printf("%lld",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
