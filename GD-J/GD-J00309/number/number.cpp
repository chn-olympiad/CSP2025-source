#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000005],cnt;
bool cmp(int a,int b){return a>b;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if('0'<=s[i]&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	cout<<endl;
	return 0; 
} 
