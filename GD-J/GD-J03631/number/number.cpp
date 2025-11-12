#include<bits/stdc++.h>
#define int long long
const int N=1e6+10;
using namespace std;
string s;
int n,cnt,a[N];
bool cmp(int p,int q){
	return p>q;
}
signed main(){
	freopen("number.in","r","std.in");
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i) if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;++i) cout<<a[i];
	freopen("number.out","w","std.out");
	return 0;
}
