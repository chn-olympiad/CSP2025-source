#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned long long;
using namespace std;
/*
zhangchenge
*/
string s,t;
void solve(){
	cin>>s;
	f(i,0,s.size()-1){
		if(s[i]<='9'&&'0'<=s[i]){
			t+=s[i];
		}
	}sort(t.begin(),t.end(),greater<char>());
	cout<<t;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--)solve();
}
