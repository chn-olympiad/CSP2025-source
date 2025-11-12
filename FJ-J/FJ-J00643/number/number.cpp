#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 214514;
int _,n,m,k,t,a[N],b[N],ans,cnt;
string s;
bool vis[N],f;
void solve(){
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]){
			cout<<i;
			b[i]--;
		}
	}
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_=1;
	while(_--){
		solve();
	}
}
