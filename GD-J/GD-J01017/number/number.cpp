#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s,ans;
int len,a[1000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	len=s.size();
	for (int i=0;i<len;++i){
		if (s[i]>='0'&&s[i]<='9'){
			++a[s[i]-'0'];
		}
	}
	for (int i=9;i>=0;i--){
		while (a[i]){
			ans+=i+'0';
			--a[i];
		}
	}
	cout<<ans;
	return 0;
}
