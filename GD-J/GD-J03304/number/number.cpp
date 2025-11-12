#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n[N],cnt = 1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i = 0; i <= s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			n[cnt] += s[i]-'0';
			cnt++;
		}
	}
	sort(n,n + cnt);
	for(int i = cnt - 1; i >= 1;i--){
		cout<<n[i];
	}
	return 0;
}
