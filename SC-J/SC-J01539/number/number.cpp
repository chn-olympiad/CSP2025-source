#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],tot=0;
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i] && s[i]<='9') a[++tot]=s[i]-'0';
	}
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--) cout<<a[i];
	return 0;
}
