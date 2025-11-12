#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int ans[N],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	int len=s.size();
	for (int i=0; i<len; i++){
		if (s[i]>='0' && s[i]<='9') ans[++n]=(s[i]-'0');
	}
	sort(ans+1,ans+1+n,cmp);
	for (int i=1; i<=n; i++) cout<<ans[i];
	cout<<'\n';
	return 0;
}
