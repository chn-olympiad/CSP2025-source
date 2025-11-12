#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10;
string s;
ll n,t[N],ans[N],tot;
inline ll read(){
	ll x=0,f=1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.length();
	s = "#"+s;
	for(ll i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
//	for(int i=0;i<=9;i++){
//		cout<<t[i]<<" ";
//	}
	for(ll i=9;i>=0;i--){
		while(t[i]>=1){
			ans[++tot] = i;
			t[i]--;
		}
	}	
	for(ll i=1;i<=tot;i++){
		printf("%lld",ans[i]);
	}
	return 0;
}
/*
290es1q0
*/
