#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10+10;
ll cnt[N],len;
string s,build;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(ll i=0;i<len;i++)
		if(isdigit(s[i])) cnt[s[i]-'0']++;
	for(ll i=9;i>=0;i--){
		while(cnt[i]){
			build+=i+'0';
			cnt[i]--;
		}
	}
	cout<<build;
	return 0;
}
