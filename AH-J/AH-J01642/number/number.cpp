#include"bits/stdc++.h"
using namespace std;
string s;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(char c:s)
	if('0'<=c&&c<='9')
		++cnt[c^48];
	for(int i=9;i>=0;--i)
	while(cnt[i]>0)cout<<i,--cnt[i];
	cout<<"\n";
}
