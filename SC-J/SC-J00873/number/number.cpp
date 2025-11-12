#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=1e5+5;
vector<int>num;
string s;
void solve(){
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)if('0'<=s[i]&&s[i]<='9')num.push_back(s[i]-'0');
	sort(num.begin(),num.end());
	len=num.size();
	for(int i=len-1;~i;i--)cout<<num[i];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}