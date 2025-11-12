#include<bits/stdc++.h>
using namespace std;
long long const N=1e7;
string s;
long long a[N],n,t=0;
bool gz(long long x,long long y) {
	return x>y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<n;i++) {
		if('0'<=s[i]&&s[i]<='9') a[t]=s[i]-'0',t++;
	}
	sort(a,a+t,gz);
	for(long long i=0;i<t;i++) cout<<a[i];
	return 0;
}