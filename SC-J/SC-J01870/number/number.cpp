#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s;
int a[N],num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();++i){
		if(s[i]>='0'&&s[i]<='9') a[++num]=s[i]-'0';
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;--i) cout<<a[i];
	return 0;
}
