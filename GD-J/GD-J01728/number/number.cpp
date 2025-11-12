#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt[1288];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<(long long)s.length();i++){
		cnt[s[i]]++;
	}
	for(char c='9';c>='0';c--){
		long long x=c;
		for(long long i=1;i<=cnt[x];i++)cout<<x-48;
	}
	return 0;
}
