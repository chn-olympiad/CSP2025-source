#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
string s;
int a[N];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned i=0;i<s.size();i++){
		if(isdigit(s[i]))a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt,greater<int>());
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}

