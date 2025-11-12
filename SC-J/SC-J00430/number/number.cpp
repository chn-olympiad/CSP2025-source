#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+3;
char s[N];
int n,cnt[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		if(s[i]>='0'&&s[i]<='9') ++cnt[s[i]-'0'];
	}
	for(int i=9;i>=0;--i) for(int j=1;j<=cnt[i];++j)  cout<<i;
	cout<<"\n";
	return 0;
}